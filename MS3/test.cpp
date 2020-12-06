LineManager::LineManager(const std::string& filename, std::vector<Workstation*>& workstation, std::vector<CustomerOrder>& comp) : m_cntCustomerOrder(0)
{
    std::ifstream m_file(filename);

    std::string tempstr, WorkStation1, WorkStation2;

    if (!m_file)
    {
        std::cerr << "File does not exist!";
    }
    else
    {
        std::move(comp.begin(), comp.end(), std::back_inserter(ToBeFilled));

        std::reverse(ToBeFilled.begin(), ToBeFilled.end());

        std::copy(workstation.begin(), workstation.end(), std::back_inserter(AssemblyLine));

        m_cntCustomerOrder = ToBeFilled.size();

        while (std::getline(m_file, tempstr))
        {
            WorkStation1 = tempstr.substr(0, tempstr.find_first_of('|'));

            if (tempstr.find('|') != std::string::npos)
            {
                WorkStation2 = tempstr.substr(tempstr.find_first_of('|') + 1, tempstr.length());
            }
            else
            {
                WorkStation2 = " ";
            }

            Workstation* stationptr1 = nullptr;
            Workstation* stationptr2 = nullptr;

            for (auto i = 0u; i < workstation.size(); ++i)
            {
                if (workstation[i]->getItemName() == WorkStation1)
                {
                    stationptr1 = workstation[i];
                    break;
                }
            }

            for (auto j = 0u; j < workstation.size(); ++j)
            {
                if (workstation[j]->getItemName() == WorkStation2)
                {
                    stationptr2 = workstation[j];
                    break;
                }
            }

            if (stationptr2 != nullptr)
            {
                stationptr1->setNextStation(*stationptr2);
            }

            if (stationptr2 == nullptr)
            {
                break;
            }
        }

        WorkStation1.clear();
        WorkStation2.clear();
    }
}