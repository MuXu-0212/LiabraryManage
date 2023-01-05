#ifndef _head_h_
#define _head_h_

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define MAXSIZE_USER 2             //用户个数
#define MAXSIZE_BOOK_NAME 30        //书名最大长度
#define MAXSIZE_BOOK_WRITER 20      //作者名最大长度
#define MAXSIZE_BOOK_NUM 20         //书籍种类最大存储数

typedef struct book_info{
    char bookname[MAXSIZE_BOOK_NAME];
    char writer[MAXSIZE_BOOK_WRITER];
    int id;
    int num;
    float price;
}book, *writting;

int len;

extern void Menu();     //主菜单
extern void Fuc_Add_Newbook(writting Book);     //添加新书(书名、作者、数量、价格)

extern void Menu_FindBook();    //查询菜单
extern void Fuc_FindBook(writting Bookname);   //查询功能
extern void Fuc_FindBook_BookName(writting Book, char* name);   //输入书名查询
extern void Fuc_FindBook_BookWriter(writting Book, char* name);   //输入作者查询
extern void Fuc_FindBook_BookId(writting Book, int id);   //输入编号查询

extern void Fuc_FindBook_Borrow(writting Book, int i);    //还书功能

extern void Fuc_AddBook(writting Book);  //增加书籍功能；判断是否存在该书，有，则数量加一
                                        //没有，则添加该书目

extern void Menu_DelBook();     //删除旧书菜单
extern void Fuc_DelBook_IsDelete(writting Book, int flag, int i);//删除旧书，并显示当前编号信息
extern void Fuc_DelBook(writting Book);     //删除旧书功能


extern void Menu_ReturnBook();  //还书菜单
extern void Fuc_ReturnBook_IsExist_bookname(writting Book); //输入书名还书
extern void Fuc_ReturnBook_IsExist_writer(writting Book);   //输入作者还书
extern void Fuc_ReturnBook_IsExist_id(writting Book);   //输入编号还书
extern void Fuc_ReturnBook(writting Book);  //书在册，则数量加一，不存在，则新增书目

extern void print_(int n);  //分割线
extern void Fuc_BookList_format(writting Book); //书籍信息对齐
extern void Fuc_BookList(writting Book);    //打印图书列表






// void Is_InputTrue(int f_argc, char* f_argv[], char* user_account[], char* user_password[])   
// {
// 	int flag = 0;        //判断密码,如果正确则flag=1
//     int i = 0;
//     if (f_argc == 3)       
//     {
//         for (i=0; i<MAXSIZE_USER; i++)
//         {
//         	if (strcmp(user_account[i], f_argv[1]) == 0 
//         		            && strcmp(user_password[i], f_argv[2]) == 0)
//         	{
//         		flag=1;
//         	}
//         }

//         if (flag)
//         {
//         	printf("input true!\n");
//         }
//         else
//         {
//         	printf("error!\n");
//         }
//     }
//     else
//     {
//     	printf("error!\n");
//     }
// }
#endif