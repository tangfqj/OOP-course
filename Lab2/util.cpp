#include "util.h"

#include <sstream>
using namespace std;

/**
 * @brief split single line string (Do not contain "\n") by delimiter to at most max_part
 * e.g "1,2,3,4" by "," at most 4 part => ["1","2","3","4"]
 *     "1,2,3,4" by "," at most 5 part => ["1","2","3","4"]
 *     "1,2,3,4" by "," at most 3 part => ["1","2","3,4"]
 * @param str any string
 * @param delim any char delimiter
 * @param max_part
 * @return vector<string> containing splitted string
 */
vector<string> split(const string& str, char delim, int max_part) {
    vector<string> res;
    // TODO: complete this function
    /* Your Code Here */
    int s=0, j, delim_num=0;
    int size = str.size();
    for (j=0; j<size; j++){
        if (str[j] == delim)
            delim_num++;
    }
    if (max_part > delim_num+1)
        max_part = delim_num+1;
    for (j=0; j<size && max_part != 0; j++){
        if (str[j] == delim && max_part != 1){
            res.push_back(str.substr(s, j-s));
            s = j+1;
            max_part--;
        }
        if (max_part == 1){
            j=str.size();
            res.push_back(str.substr(s, j-s));
            max_part--;
        }
    }
    return res;
    }

/**
 * @brief output info string to os and mark it green
 *
 * @param os any output stream, usually cout
 * @param str any string
 * @return ostream& the original output stream
 */
ostream& output_info(ostream& os, const string& str) {
    os << "\033[32m" << str << "\033[0m";
    return os.flush();
}

/**
 * @brief output error string to os and mark it red
 *
 * @param os any output stream, usually cerr
 * @param str any string
 * @return ostream& the original output stream
 */
ostream& output_error(ostream& os, const string& str) {
    // TODO: complete this function
    /* Your Code Here */
    os << "\033[31m" << str << "\033[0m";
    return os.flush();
}