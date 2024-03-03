
//need delete ../include/
#include "../include/Qpreinclude.h"

#include <stdio.h>
#include "../include/QDNS.h"

int main(){
    // 全局
    initGlobalDns();
    Dns_all * pd=getGlobalDns();
    // SHOW_FLAGS("globalDns.header.TRANS_ID",pd->header.TRANS_ID);
    //  SHOW_FLAGS("globalDns.header.TRANS_ID",*pd);
    
    setQueryUrl("www.baidu.com");
    SHOW_GLOBAL_DELETEME();
    
    return 0;
}