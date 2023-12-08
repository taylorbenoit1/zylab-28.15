#include "PlaylistNode.h"
#include <iostream>


PlaylistNode::PlaylistNode()
    : uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(nullptr) {}


PlaylistNode::PlaylistNode(std::string id, std::string song, std::string artist, int length)
    : uniqueID(id), songName(song), artistName(artist), songLength(length), nextNodePtr(nullptr) {}


std::string PlaylistNode::GetID() const { return uniqueID; }
std::string PlaylistNode::GetSongName() const { return songName; }
std::string PlaylistNode::GetArtistName() const { return artistName; }
int PlaylistNode::GetSongLength() const { return songLength; }
PlaylistNode* PlaylistNode::GetNext() const { return nextNodePtr; }


void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {
    nodePtr->nextNodePtr = this->nextNodePtr;
    this->nextNodePtr = nodePtr;
}

void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
    this->nextNodePtr = nodePtr;
}


void PlaylistNode::PrintPlaylistNode() const {
    std::cout << "Unique ID: " << uniqueID << std::endl;
    std::cout << "Song Name: " << songName << std::endl;
    std::cout << "Artist Name: " << artistName << std::endl;
    std::cout << "Song Length (in seconds): " << songLength << std::endl;
    std::cout << std::endl;
}
