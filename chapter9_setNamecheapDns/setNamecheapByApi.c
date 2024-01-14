#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>

#define BUFFSIZE 256
#define NAMECHEAPAPI 0

/** TODO 没啥用，只是为了让编译器不报错，可以在路由器上更新了，代码只是为了测试
 *  已经在路由器上写了一个脚本,先ifconfig 找出ISP分配的地址，然后和旧的地址比较，如果不一样，就更新
 *  更新也就是如下代码了,以下为Namecheap的API，需要在Namecheap的控制台上设置
 *  找到advacen DNS，然后action,action表示可以用API访问这个接口 @表示主机名，domain填写域名，password填写API的密码
 *  host设置为www的时候 表示www.购买的域名.com，如果设置为@，表示当前购买的域名.com
 *  host填写@，ip填写任意，然后保存，然后就可以用API更新了
*/

#define __STR(x)    #x
#define _STR(x)  __STR(x)

#define NAMECHEAPDOMAIN "didi.com"
#define NAMECHEAPPASSWD "FAKE_API49733c1135b84b95a13f79f64c62746b"
#define NAMECHEAPHOST "@"

#if NAMECHEAPAPI
https://dynamicdns.park-your-domain.com/update?host=@&domain=didi.com&password=fkae49733c1135b84b95a13f79f64c62746b&ip=%s
#endif 

int main(int argc,char *argv[])
{
    if(argc !=2){
        printf("Usage: %s  <ip>\n ",argv[0]);
        exit(-1);
    }

    return 0;
    
    char BUFF[BUFFSIZE];
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    sprintf(BUFF,"https://dynamicdns.park-your-domain.com/update?host=%s&domain=%s&password=%s&ip=%s",NAMECHEAPHOST,NAMECHEAPDOMAIN,NAMECHEAPPASSWD,argv[1]);

    curl = curl_easy_init();
    if(curl) {
        // 替换为你的域名、密码（或者token）和需要绑定的IP
        // curl_easy_setopt(curl, CURLOPT_URL, "https://dynamicdns.park-your-domain.com/update?host=@&domain=yourdomain.com&password=yourpassword&ip=yourip");

        /* 如果你想要看到更多的信息，可以取消下面这行的注释 */
        /* curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); */


        curl_easy_setopt(curl, CURLOPT_URL, BUFF);
        res = curl_easy_perform(curl);

        /* 检查错误 */
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

        /* always cleanup */
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return 0;
}