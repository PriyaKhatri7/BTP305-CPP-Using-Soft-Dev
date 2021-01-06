#include <iostream>
#include <iomanip>//setw
#include "SongCollection.h"
using namespace std;

namespace sdds
{
	SongCollection::SongCollection(const std::string& strSong) :
		m_song{ nullptr }
	{
		if (!m_song) //if the filename is incorrect throw an exception
		{
			throw "Filename is incorrect**";
		}
		else
		{
			//title
			size_t title_delimiter = strSong.find('\0');
			int title_start = strSong.find_first_not_of(" ", 0);
			int title_end = strSong.find_last_not_of(" ", title_delimiter - 1);
			int title_len = (title_end - title_start) + 1;
			string title = strSong.substr(title_start, title_len);
			this->m_title = title;

			//artist
			size_t artist_delimiter = strSong.find('\0');
			int artist_start = strSong.find_first_not_of(" ", 0);
			int artist_end = strSong.find_last_not_of(" ", title_delimiter - 1);
			int artist_length = (artist_end - artist_start) + 1;
			string artist = strSong.substr(artist_start, artist_length);
			this->m_artist = artist; 
			
			//album
			size_t album_delimiter = strSong.find('\0');
			int album_start = strSong.find_first_not_of(" ", artist_delimiter + 1);
			int album_end = strSong.find_last_not_of(" ", artist_delimiter - 1);
			int album_length = (album_end - album_start) + 1;
			string album = strSong.substr(album_start, album_length);
			this->m_album = album;

			//year
			size_t year_delimiter = strSong.find(',', album_delimiter + 1);
			int year_start = strSong.find_first_not_of(" ", album_delimiter + 1);
			int year_end = strSong.find_last_not_of(" ", year_delimiter - 1);
			int year_length = (year_end - year_start) + 1;
			string year1 = strSong.substr(year_start, year_length);
			int year2 = stoi(year1);
			this->m_year = year2;

			//length
			size_t desc_delimiter = strSong.find('\0');
			int desc_start = strSong.find_first_not_of(" ", year_delimiter + 1);
			int desc_end = strSong.find_last_not_of(" ", desc_delimiter);
			int desc_length = (desc_end - desc_start) + 1;
			string desc = strSong.substr(desc_start, desc_length);
			double desc2 = stod(desc);
			this->m_length = desc2;

			//price
			size_t price_delimiter = strSong.find('\0');
			int price_start = strSong.find_first_not_of(" ", desc_delimiter + 1);
			int price_end = strSong.find_last_not_of(" ", price_delimiter - 1);
			int price_length = (price_end - price_start) + 1;
			string price1 = strSong.substr(price_start, price_length);
			double price2 = stod(price1);
			this->m_price = price2;

		}

	}

	void SongCollection::display(std::ostream& out) const
	{
		out << "----------------------------------------------------------------------------------------" << endl;
		out << operator<<;
		out << "----------------------------------------------------------------------------------------" << endl;

	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
		out << setw(20) << theSong.m_title << " | ";
		out << setw(15) << theSong.m_artist << " | ";
		out << setw(20) << theSong.m_album << " | ";
		out << setw(6) << theSong.m_year << " | ";
		out << theSong.m_length << " | " << theSong.m_price << " | " << endl;
		
		return out; 
	}


}