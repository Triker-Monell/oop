#!/usr/bin/env python
# -*- coding=utf-8 -*-
import sys
import urllib
import os
from imp import reload
reload(sys)
sys.setdefaultencoding('utf-8')
from bs4 import BeautifulSoup
def get_html(url):  #通过url获取网页内容
    result = urllib.urlopen(url)
    return result.read()
    # save_file(result.read(), 'thefile.txt')
def get_movie_url(url):
    html=get_html(url)
    soup=BeautifulSoup(html,"html.parser")
    name=soup.find('a', class_="nbg")
    url=name.get('href')
    return url

def get_all_photos(url):
    t = 1  # 记录张数
    os.chdir(os.path.join(os.getcwd(), '/home/monell/qtcode/build-InfoCS-Desktop_Qt_5_10_1_GCC_64bit-Debug/allphotos'))
    for i in range(0, 300, 30):

        photos_url = url+'/photos?type=S&start='+str(i)+'&sortby=like&size=a&subtype=a'

        html = get_html(photos_url)
        soup=BeautifulSoup(html,"html.parser")

        src =soup.find_all('ul', class_="poster-col3 clearfix",id="")

        for myimg in src:

            the_img_src = myimg.find_all('img')

            for the_img_src_it in the_img_src:
                pic_name = str(t) + '.jpg'
                img_src = the_img_src_it.get('src')
                urllib.urlretrieve(img_src, pic_name)
                t += 1

    os.chdir(r'/home/monell/qtcode/build-InfoCS-Desktop_Qt_5_10_1_GCC_64bit-Debug')

def get_movie_all(html):     #通过soup提取到每个电影的全部信息，以list返回
    soup = BeautifulSoup(html, "html.parser")
    movie_1 = soup.find_all('title')
    movie_2 = soup.find_all('div', id='info')
    movie_3 = soup.find_all('strong', class_="ll rating_num" ,property="v:average")
    movie_4 = soup.find_all('div', class_="ratings-on-weight")
    movie_5 = soup.find_all('ul' ,class_="related-pic-bd")
    movie_6 = soup.find_all('div', id="mainpic" ,class_="")
    movie_str=str(movie_1[0])+str(movie_2[0])+str(movie_3[0])+str(movie_4[0])+str(movie_5[0])+str(movie_6[0])
    movie=[movie_str]
    return movie
def get_movie_one(movie,name):
    result = []  # 用于存储提取出来的电影信息
    soup_all = BeautifulSoup(str(movie), "html.parser")
    title = soup_all.find_all('title')
    soup_title = BeautifulSoup(str(title[0]), "html.parser")
    for line in soup_title.stripped_strings:  # 对获取到的<a>里的内容进行提取
        result.append(line)



    result_str=""

    info = soup_all.find_all('div', id='info')
    for it in info:
        soup_info = BeautifulSoup(str(it), "html.parser")
        for line in soup_info.stripped_strings:
            result_str = result_str +' / ' +line


    rating=soup_all.find_all('strong', class_="ll rating_num", property="v:average")
    soup_rating = BeautifulSoup(str(rating[0]),"html.parser")
    for line in soup_rating.stripped_strings:
        result_str=result_str+" 评分: "+line+" / "


    result_str=result_str+" 星级： "
    starlevel = soup_all.find_all('div' ,class_="ratings-on-weight")
    for it in starlevel:
        soup_starlevel = BeautifulSoup(str(it),"html.parser")
        for line in soup_starlevel.stripped_strings:
            result_str = result_str+line+ " "

    os.chdir(os.path.join(os.getcwd(), '/home/monell/qtcode/build-InfoCS-Desktop_Qt_5_10_1_GCC_64bit-Debug/photos'))
    t=0
    post = soup_all.find_all('div', id="mainpic" ,class_="")
    for it in post:
        goal=it.find('img')
        pic_name = unicode(name.rstrip().replace(' ','_')+str(t)+'.jpg','utf-8')
        img_src= goal.get('src')
        urllib.urlretrieve(img_src, pic_name)

    t=1 #记录张数
    src=soup_all.find_all('ul' ,class_="related-pic-bd")
    for myimg in src:

        the_img_src=myimg.find_all('img')

        for the_img_src_it in the_img_src:
            pic_name =unicode(name.rstrip().replace(' ','_')+ str(t) + '.jpg','utf-8')
            img_src = the_img_src_it.get('src')
            urllib.urlretrieve(img_src, pic_name)
            t+=1



    os.chdir(r'/home/monell/qtcode/build-InfoCS-Desktop_Qt_5_10_1_GCC_64bit-Debug')
    result.append(result_str)

    return result  #返回获取到的结果
def save_file(text, filename):  #保存网页到文件
    f= open(filename,'ab')
    f.write(bytes(text))
    f.close()
def read_file(filename):  #读取文件
    f = open(filename,'r')
    text = f.read()
    f.close()
    return text
def work():
    try:
        f = open('/home/monell/qtcode/build-InfoCS-Desktop_Qt_5_10_1_GCC_64bit-Debug/Douban_by_movies.txt', 'r')

        name=f.read()
    finally:
        if f:

            f.close()
            w = open('/home/monell/qtcode/build-InfoCS-Desktop_Qt_5_10_1_GCC_64bit-Debug/Douban_by_movies.txt', 'w')
            w.truncate()
            w.close()
        preurl = 'https://www.douban.com/search?cat=1002&q='+str(name)
        url=get_movie_url(preurl)
        html = get_html(url)
        movie_list = get_movie_all(html)
        for movie in movie_list:  # 将每一页中的每个电影信息放入函数中提取
            result = get_movie_one(movie,name)
            text = '' + '电影名： ' + str(result[0])  + str(result[1]) + '\n' + '\t'
            save_file(text, '/home/monell/qtcode/build-InfoCS-Desktop_Qt_5_10_1_GCC_64bit-Debug/Douban_by_movies.txt')
        #get_all_photos(url)

if __name__=='__main__':
   work()
