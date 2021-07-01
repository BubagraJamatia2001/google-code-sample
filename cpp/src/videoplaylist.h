#pragma once

#include "videolibrary.h"
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
/** A class used to represent a Playlist */
struct CaseInsensitiveLess
{
	bool operator()(std::string lhs, std::string rhs)
	{
		transform(lhs.begin(), lhs.end(), lhs.begin(),
			[](char c) { return std::tolower(c); });
		transform(rhs.begin(), rhs.end(), rhs.begin(),
			[](char c) { return std::tolower(c); });
		return lhs < rhs;
	}
};
class VideoPlaylist {
public:
	std::map < std::string, std::vector<const Video*>, CaseInsensitiveLess> videoPL;
	VideoPlaylist() = default;

	// This class is not copyable to avoid expensive copies.
	VideoPlaylist(const VideoPlaylist&) = delete;
	VideoPlaylist& operator=(const VideoPlaylist&) = delete;

	// This class is movable.
	VideoPlaylist (VideoPlaylist&&) = default;
	VideoPlaylist& operator=(VideoPlaylist&&) = default;
	/*
	void create_playlist(const std::string& playlist);
	void add_to_playlist(const std::string& playlist, const std::string& videoId);
	void show_all_playlists();
	void show_playlist(const std::string& playlist);
	void remove_from_playlist(const std::string& playlist, const std::string& videoId);
	void clear_playlist(const std::string playlist);
	void delete_playlist(const std::string playlist);
	*/
};
