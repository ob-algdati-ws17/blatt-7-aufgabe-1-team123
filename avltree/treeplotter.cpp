//
// Created by Robert on 03.05.2018.
//

#include "treeplotter.h"
#include <windows.h>
#include "iostream"
#include "fstream"

void treeplotter::plot(AVLTree *tree){
    plot(tree->root);
}

void treeplotter::plot(AVLTree::Node *root){
    string json =  getJSON(root);
    writeJSON(json);
}


string treeplotter::getJSON_data(AVLTree::Node *node){
    string json_data = "{ text: {name:\"" + std::to_string(node->key) + "\" , balance:\"" + std::to_string(node->balance) + "\"}, children: [";
    if(node->left == nullptr){
        json_data += "{},";
    }else{
        json_data += getJSON_data(node->left) + ",";
    }
    if(node->right == nullptr){
        json_data += "{}";
    }else{
        json_data += getJSON_data(node->right);
    }
    json_data += "]}";
    return json_data;
}
/**
 *
 * @param root wurzel des Baumes
 * @return jsonString
 */
string treeplotter::getJSON(AVLTree::Node *node){
    if(node == nullptr){
        cout << "empty tree";
        return "empty tree";
    }
    string json_start = "var chart_config = {\n"
            "        \"chart\": {\n"
            "            \"container\": \"#collapsable-example\",\n"
            "\n"
            "            \"animateOnInit\": true,\n"
            "            \n"
            "            \"node\": {\n"
            "                \"collapsable\": true\n"
            "            },\n"
            "            \"animation\": {\n"
            "                \"nodeAnimation\": \"easeOutBounce\",\n"
            "                \"nodeSpeed\": 700,\n"
            "                \"connectorsAnimation\": \"bounce\",\n"
            "                \"connectorsSpeed\": 700\n"
            "            }\n"
            "        },\n"
    ;
    string json_data = "\"nodeStructure\": " + getJSON_data(node);
    string result = json_start + json_data + "};";
    //std::cout << result;
    return result;
}

bool hasEnding (std::string const &fullString, std::string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

void treeplotter::writeJSON(string json){
    //for windows only:
    char buffer[MAX_PATH];
    GetModuleFileName( NULL, buffer, MAX_PATH );
    string::size_type pos = string( buffer ).find_last_of( "\\/" );
    string dir =  string( buffer ).substr( 0, pos);
    string ending = "cmake-build-debug\\test";
    if(hasEnding(dir,ending)){
        cout << endl << endl <<  dir.substr(0,dir.length()-ending.length()) << endl << dir;
    }
    string new_dir = dir.substr(0,dir.length()-ending.length());
    ofstream f;
    f.open("..\\..\\Frontend\\projekt\\examples\\collapsable\\collapsable.js", ios::out | ios::trunc);
    f << json;
    f.close();
}