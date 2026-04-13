#include<bits/stdc++.h>
using namespace std;

/*


Core apis and functionalitys :


-string ls(string path) : for a file path : will return the file name, for a folder, will return all its children

create a new folder at this path

-mkdir(string path)

-readFromFile(string path)

-writeTOFile(string path, string content)


Node
-name


FileNode
-string content

DirectoryNode
// other children for this
map<string, Node*> children


FileSystem class main
-DirectoryNode* root

string ls()
*/


class Node{

    public :
    string name;
    bool isFile;
    unordered_map<string, Node*> children; // just like a trieNode : for the children : eg : ab/ bc
    // ab/ cd 
    // cd -> Node*
    // bc -> Node*
    // lookup is faster for this case :using an unordered map for the subfolders : subnodes

    Node(string name) : name(name), isFile(false) {};

    string getName(){
        return name;
    }
    virtual vector<string> ls() = 0;

    // virtual ~Node() = default;
};


class File : public Node {

    public : 

    File(string name) : Node(name) {
        isFile = true;
    }

    vector<string> ls(){
        return {Node ::getName()};
    }
    
};


class Folder : public Node {

    
};

class FileSystem{


    public : 


    // it will list all the contents inside the directory pah
    vector<string> ls(string path){

    }

    // create a new folder under the path
    void mkdir(string path){

    }


    string readFromPath(string path){

    }

    // file path : shpould be a valid path
    void addContentToPath(string path){

    }



};



