
#include <string>

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONG_COLLECTION_H

namespace sdds
{
	
	struct Song
	{
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price;
		int m_year;
		double m_length;

	};

	class SongCollection : public Song
	{
		Song* m_song; //collection of objects of type Song

	public:
		SongCollection(const std::string& strSong); //custom 
		void display(std::ostream& out) const;
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);

}
#endif // !SDDS_SONGCOLLECTION_H