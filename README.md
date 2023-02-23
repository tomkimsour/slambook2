## Slambook2

![titlepage](./figures/title.png)

Welcome to Slambook 2nd Edition! This is the codebase of our book. Here are some relavant links if you need them:

- [Our book at jd.com](https://item.jd.com/12666058.html)
- [Our book at douban.com](https://book.douban.com/subject/27028215/) (I'll be happy to get a score at douban)
- [code of slambook version 1](https://github.com/gaoxiang12/slambook)
- [slambook in English](https://github.com/gaoxiang12/slambook-en) (Still on going)

Email me if you have any questions: gao.xiang.thu at gmail dot com. Or send a issue at github if your question is about the code.

Errata will be updated at this code base.

Hope you like this book.

BaiduYun backup link in case your github is very slow (common in China): [here](https://pan.baidu.com/s/1XQwpnDb3BOvxXZhL-03p3w)

---

## 视觉 SLAM 十四讲：从理论到实践 第二版

欢迎来到视觉 SLAM 十四讲：从理论到实践。这里存放本书对应的代码文件。以下是一些可能对你有用的链接：

- [京东书籍链接](https://item.jd.com/12666058.html)
- [第一版书代码](https://github.com/gaoxiang12/slambook)
- [英文版代码](https://github.com/gaoxiang12/slambook-en) (正在翻译中)

如果您对书籍内容有疑问，请给我发送邮件。如果对代码有疑问，请点击上方的 issue 链接新建 issues。我会不定期查看和回复（抱歉我可能无法回复所有问题和邮件）。

勘误表会更新到代码库中。

希望您喜欢本书。

本代码的百度云备份（如果您的 github 速度非常慢）[下载链接](https://pan.baidu.com/s/1XQwpnDb3BOvxXZhL-03p3w).

## Build

The project uses c++14
Libraries version :

- ceres-solver : 2.0.0
- g2o : e8df2004e07ea8f5b8e6a8b9f2dc067b45b45036 (hash of the git repo)
- googletest : 1.13.0  
- pangolin : 1ec721d59ff6b799b9c24b8817f3b7ad2c929b83 (hash of the git repo)
- Sophus : v22.10

## How to install libraries

- download the git repository from github using ```git clone```
- checkout the appropriate git commit
- compile ```mkdir build && cd build && cmake .. . && make -j4```
- install it on your machine if it compiled properly ```sudo make install```
