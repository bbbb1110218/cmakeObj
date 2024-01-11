#include <boost/filesystem/file_status.hpp>
#include <iostream>
#include <boost/filesystem.hpp>

int main(){
    using std::cout;
    using std::endl;
    boost::filesystem::directory_entry p("/Users/min122218/Documents/GitHub/cmakeObj/chapter7_boost/deleteme");
     boost::filesystem::directory_entry p2("/Users/min122218/Documents/GitHub/cmakeObj/chapter7_boost/replaceDeleteNow");
    // boost::filesystem::file_type type=static_cast<boost::filesystem::file_type>(p.status().type());
    p.replace_filename(p2);

    cout << p.path() << endl;
    return 0;
}