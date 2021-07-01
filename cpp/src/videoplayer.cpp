#include "videoplayer.h"
#include "videoplaylist.h"

#include <iostream>
#include <algorithm>

using namespace std;

void VideoPlayer::numberOfVideos() {
  std::cout << mVideoLibrary.getVideos().size() << " videos in the library"
            << std::endl;
}

void VideoPlayer::showAllVideos() {
  std::cout << "Here's a list of all available videos:" << std::endl;
  std::vector<Video> ans = mVideoLibrary.getVideos();
  sort(ans.begin(), ans.end(), [](Video a, Video b) {return a.getTitle() < b.getTitle(); });
  for (auto it : ans) {
      std::cout << it.getTitle() << " (" << it.getVideoId() << ") [";
      for (auto i : it.getTags()) {
          std::cout << i ;
          if (i != it.getTags().back())
              std::cout << " ";
      }
      std::cout << "]\n";
  }
}

void VideoPlayer::playVideo(const std::string& videoId) {
    const Video* curr = mVideoLibrary.getVideo(videoId);
    if (currentlyPlaying.empty()) {
        if (curr != nullptr) {
            std::cout << "Playing video: "<< curr->getTitle() << std::endl;
            currentlyPlaying.push(mVideoLibrary.getVideo(videoId));
            stop = false;
            paused = false;
        }
        else {
            std::cout << "Cannot play video: Video does not exist" << std::endl;
        }
    }
    else{
        if (curr != nullptr) {
            std::cout << "Stopping video: " << currentlyPlaying.front()->getTitle() << std::endl;
            currentlyPlaying.pop();
            std::cout << "Playing video: "<< curr->getTitle() << std::endl;
            currentlyPlaying.push(mVideoLibrary.getVideo(videoId));
            stop = false;
            paused = false;
        }
        else {
            std::cout << "Cannot play video: Video does not exist" << std::endl;
        }
    }
 
}

void VideoPlayer::stopVideo() {
    if (currentlyPlaying.empty()) {
        std::cout << "Cannot stop video: No video is currently playing" << std::endl;
    }
    else {
        const Video* curr = currentlyPlaying.front();
        if (!stop) {
            std::cout << "Stopping video: " << curr->getTitle() << std::endl;
            stop = true;
        }
        else {
            std::cout << "Cannot stop video: No video is currently playing" << std::endl;
        }
    }
 
}

void VideoPlayer::playRandomVideo() {
    std::vector<Video> options = mVideoLibrary.getVideos();
    //std::cout << mVideoLibrary.getVideos().size()<< " ";
    int randIndx = (int)rand() % options.size();
    // std::cout << randIndx <<" " << options[randIndx].getVideoId()<< "\n";
    playVideo(options[randIndx].getVideoId());
}

void VideoPlayer::pauseVideo() {
    if (currentlyPlaying.empty()) {
        std::cout << "Cannot pause video: No video is currently playing" << std::endl;
    }
    else {
        const Video* curr = currentlyPlaying.front();
        if (!paused) {
            paused = true;
            std::cout << "Pausing video: " << curr->getTitle()<<std::endl;
        }
        else {
            std::cout << "Video already paused: " << curr->getTitle() << std::endl;
        }
    }
}

void VideoPlayer::continueVideo() {
    if (currentlyPlaying.empty() || stop){
        std::cout << "Cannot continue video: No video is currently playing" << std::endl;
    }
    else {
        const Video* curr = currentlyPlaying.front();
        if (paused) {
            std::cout << "Continuing video: " << curr->getTitle() << std::endl;
            paused = false;
        }
        else {
            std::cout << "Cannot continue video: Video is not paused" << std::endl;
        }
    }
}

void VideoPlayer::showPlaying(){
    if(currentlyPlaying.empty() || stop) {
        std::cout << "No video is currently playing" << std::endl;
    }
    else {
        const Video* curr = currentlyPlaying.front();
        std::cout << "Currently playing: " << curr->getTitle() << " (" << curr->getVideoId() << ") [";
        for (auto i : curr->getTags()) {
            std::cout << i;
            if (i != curr->getTags().back())
                std::cout << " ";
        }
        std::cout << "]";
        if (paused)
            std::cout << " - PAUSED" << std::endl;
        else
            std::cout << std::endl;
    }
}


void VideoPlayer::createPlaylist(const std::string& playlistName) {
}
   

void VideoPlayer::addVideoToPlaylist(const std::string& playlistName, const std::string& videoId){
  
}

void VideoPlayer::showAllPlaylists() {
  std::cout << "showAllPlaylists needs implementation" << std::endl;
}

void VideoPlayer::showPlaylist(const std::string& playlistName) {
  std::cout << "showPlaylist needs implementation" << std::endl;
}

void VideoPlayer::removeFromPlaylist(const std::string& playlistName,
                                     const std::string& videoId) {
  std::cout << "removeFromPlaylist needs implementation" << std::endl;
}

void VideoPlayer::clearPlaylist(const std::string& playlistName) {
  std::cout << "clearPlaylist needs implementation" << std::endl;
}

void VideoPlayer::deletePlaylist(const std::string& playlistName) {
  std::cout << "deletePlaylist needs implementation" << std::endl;
}

void VideoPlayer::searchVideos(const std::string& searchTerm) {
  std::cout << "searchVideos needs implementation" << std::endl;
}

void VideoPlayer::searchVideosWithTag(const std::string& videoTag) {
  std::cout << "searchVideosWithTag needs implementation" << std::endl;
}

void VideoPlayer::flagVideo(const std::string& videoId) {
  std::cout << "flagVideo needs implementation" << std::endl;
}

void VideoPlayer::flagVideo(const std::string& videoId, const std::string& reason) {
  std::cout << "flagVideo needs implementation" << std::endl;
}

void VideoPlayer::allowVideo(const std::string& videoId) {
  std::cout << "allowVideo needs implementation" << std::endl;
}
