#!/usr/bin/sh
url1='http://www.yujitach.sakura.ne.jp/diary/old/profile'
url2='http://www.yujitach.sakura.ne.jp/diary/old/profile-old'
urllast='.html'
for ((i=1;i<=2500;i++))
do
#curl -O http://www.yujitach.sakura.ne.jp/diary/old/profile$i.html
url=$url1$i$urllast
a=$(curl -Ss -w '%{http_code}\n' $url -o /dev/null)
#echo $url
if [ $a -ne 404 ]; then
curl http://www.yujitach.sakura.ne.jp/diary/old/profile$i.html > profile$i.html
fi
done

for ((i=1;i<=2500;i++))
do
#curl -O http://www.yujitach.sakura.ne.jp/diary/old/profile$i.html
url=$url2$i$urllast
a=$(curl -Ss -w '%{http_code}\n' $url -o /dev/null)
#echo $url
if [ $a -ne 404 ]; then
curl http://www.yujitach.sakura.ne.jp/diary/old/profile$i.html > profile$i.html
fi
done


#a=$(curl -Ss -w '%{http_code}\n' 'http://www.yujitach.sakura.ne.jp/diary/old/profile21.html' -o /dev/null)
#echo $a

