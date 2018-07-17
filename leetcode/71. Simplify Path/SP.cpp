/*
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/
// straight O(n)
class Solution {
public:
    string simplifyPath(string path) {
        path.push_back('/');
        vector<string> dirs;
        int start = -1;
        for(int i=0;i<=path.size();++i){
            if(path[i] == '/'){
                if(start != -1 && i!=start){
                    string dir = path.substr(start, i-start);
                    if(dir == ".."){
                        if(!dirs.empty())
                            dirs.pop_back();
                    }
                    else if(dir != ".")
                        dirs.push_back(dir);
                }
                start = i+1;
            }
        }
        if(dirs.empty())
            return "/";
        string ret;
        for(string dir:dirs){
            ret.push_back('/');
            ret.append(dir);
        }
        return ret;
    }
};
