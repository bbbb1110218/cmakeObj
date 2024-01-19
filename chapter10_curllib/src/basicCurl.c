#include <stdio.h>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>

struct MemoryStruct
{
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t one, size_t contentSize, void *userp);

int main()
{

    // 在你的CURL代码中
    CURL *curl_handle;
    CURLcode res;

    struct MemoryStruct chunk;

    chunk.memory = malloc(1); /* will be grown as needed by the realloc above */
    chunk.size = 0;           /* no data at this point */

    curl_global_init(CURL_GLOBAL_ALL);

    /* init the curl session */
    curl_handle = curl_easy_init();

    /* specify URL to get */
    curl_easy_setopt(curl_handle, CURLOPT_URL, "https://www.google.com");

    /* send all data to this funct ion  */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);

    /* we pass our 'chunk' struct to the callback function */
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);

    /* get it! */
    res = curl_easy_perform(curl_handle);

    /* check for errors */
    if (res != CURLE_OK)
    {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    }
    else
    {
        /*
         * Now, our chunk.memory points to a memory block that is chunk.size
         * bytes big and contains the remote file.
         *
         * Do something nice with it!
         */
        if (chunk.size)
        {

            printf("%lu bytes retrieved\n", (long)chunk.size);
            printf("%s\n",chunk.memory);

        }
        else
        {
            printf("get NULL data\n");
        }
    }

    /* cleanup curl stuff */
    curl_easy_cleanup(curl_handle);

    free(chunk.memory);

    /* we're done with libcurl, so clean it up */
    curl_global_cleanup();
}

/** 参数说明
 * void *contents：这是从服务器接收到的数据。这个数据可能不是以NULL结尾的，所以不应该被当作字符串处理。
 * size_t size：这总是1。
 * size_t nmemb：这是接收到的数据的字节数。这个值乘以size就是contents中数据的总字节数。
 * void *userp：这是你在调用curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk)
 * 这个函数应该返回它处理的字节数，这通常是size * nmemb。如果返回的值和传入的size * nmemb不同，CURL会认为发生了错误，并停止传输
*/


static size_t WriteMemoryCallback(void *contents, size_t one, size_t contentSize, void *userp)
{
    size_t realsize = one * contentSize;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    char *ptr = realloc(mem->memory, mem->size + realsize + 1);
    if (ptr == NULL)
    {
        /* out of memory! */
        printf("not enough memory (realloc returned NULL)\n");
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}
