#include <iostream>
#include "PlaylistNode.h"
// Names of poeple who did the project:

// Taylor 
// Stephen
// Jack

using namespace std;

void PrintMenu(const string& playlistTitle) {
  cout << playlistTitle << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    
   
}

PlaylistNode* ExecuteMenu(char option, string playlistTitle, PlaylistNode* headNode) {
  switch (option) {
        case 'a': {
        string id, songName, artistName;
            int songLength;
            
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            getline(cin, id);
            cout << "Enter song's name:" << endl;
            getline(cin, songName);
            cout << "Enter artist's name:" << endl;
            getline(cin, artistName);
            cout << "Enter song's length (in seconds):" << endl;
            
            cout << endl;
            cin >> songLength;
            cin.ignore(); 

            PlaylistNode* newNode = new PlaylistNode(id, songName, artistName, songLength);

            if (headNode == nullptr) { 
                headNode = newNode;
            } else {
                PlaylistNode* currNode = headNode;
                while (currNode->GetNext() != nullptr) { 
                    currNode = currNode->GetNext();
                }
                currNode->SetNext(newNode); 
            }
            break;
        }
  
        case 'd': {
          string uniqueID;
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            getline(cin, uniqueID);

            PlaylistNode* currNode = headNode;
            PlaylistNode* prevNode = nullptr;

            while (currNode != nullptr) {
                if (currNode->GetID() == uniqueID) {
                    if (prevNode == nullptr) {
                        // Removing the head node
                        headNode = currNode->GetNext();
                    } else {
                        // Removing a non-head node
                        prevNode->SetNext(currNode->GetNext());
                    }
                    cout << "\"" << currNode->GetSongName() << "\" removed." << endl;
                    cout << endl;
                    delete currNode; // Free the memory of the node
                    break;
                }
                prevNode = currNode;
                currNode = currNode->GetNext();
            }

            if (currNode == nullptr) {
                cout << "Song with unique ID " << uniqueID << " not found." << endl;
            }
            break;
        }
        case 'c':
           
            break;
        case 's':{ 
            string artistName;
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl;
            cout << endl;
            getline(cin, artistName);

            int songNumber = 1;
            bool found = false;
            for (PlaylistNode* currNode = headNode; currNode != nullptr; currNode = currNode->GetNext()) {
                if (currNode->GetArtistName() == artistName) {
                    cout << songNumber << "." << endl;
                    currNode->PrintPlaylistNode();
                    found = true;
                }
                songNumber++;
            }

            if (!found) {
                cout << "No songs found for " << artistName << endl;
            }
            break;
        }
           
        case 't' : { 
            int totalTime = 0;
            for (PlaylistNode* currNode = headNode; currNode != nullptr; currNode = currNode->GetNext()) {
                totalTime += currNode->GetSongLength();
            }
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
            cout << "Total time: " << totalTime << " seconds" << endl;
            cout << endl;
            break;
        }

        case 'o':
         cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
            if (headNode == nullptr) {
                cout << "Playlist is empty" << endl;
                cout << endl;
            } else {
                int count = 1;
                PlaylistNode* currNode = headNode;
                while (currNode != nullptr) {
                    cout << count << "." << endl;
                    currNode->PrintPlaylistNode();
                    currNode = currNode->GetNext();
                    count++;
                }
            } 
            break;
        case 'q':
        
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
    }
    

    return headNode;
}



int main() {
   string playlistTitle;
   PlaylistNode* headNode = nullptr;
   
    cout << "Enter playlist's title:" << endl;
    cout << endl;
    getline(cin, playlistTitle);
    char menuOption;
    do {
        PrintMenu(playlistTitle);
        cout << "Choose an option:" << endl;
        cin >> menuOption;
        cin.ignore(); 
     if (menuOption != 'a' && menuOption != 'd' && menuOption != 'c' && 
            menuOption != 's' && menuOption != 't' && menuOption != 'o' && 
            menuOption != 'q') {
            cout << "Invalid option. Please try again." << endl;
            continue;
        }

        headNode = ExecuteMenu(menuOption, playlistTitle, headNode);
    } while (menuOption != 'q');

   
   return 0;
}
