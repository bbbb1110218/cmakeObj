## 目标

    得到自己的公网ip 通过namecheap设置一下
    namecheap的API要通过环境变量 要不然会暴露呀
    提前通过命令 export***="***" 不过不好使
    最好通过.vscode setting.json  cmake.envir

## 得到自己的ip

    curl 'https://api.ipify.org'
    curl ifconfig.me

## 或者 网卡得到自己的ip

ifconfig ｜grep 啥的


## host为@代表裸域名

abc.com  设置host为@的时候就是abc.com 不是www.abc.com

https://www.namecheap.com/support/knowledgebase/article.aspx/29/11/how-to-dynamically-update-the-hosts-ip-with-an-https-request/


https://dynamicdns.park-your-domain.com/update?host= **[host]** &domain= **[domain_name]** &password= **[ddns_password]** &ip=**[your_ip]**
