#include "head.h"

int main(int argc, char* argv[])    //主函数传参的方式登入
{
    //用户信息
	char* user_account[MAXSIZE_USER] = {"115", "111"};
	char* user_password[MAXSIZE_USER] = {"123", "456"};

    //图书信息
    book books[MAXSIZE_BOOK_NUM] = {

        {"Pride and Prejudice", "Jane Austen", 1, 10, 30.5},
        {"FLIPPED", "Wendelin Van Draanen", 2, 15, 50.2},
        {"Wonder", "R.0J. Palacio", 3, 6, 20.3},
        {"The Remains of the Day", "Kazuo Ishiguro", 4, 19, 17.6}
    };

    len = 4;

    int flag = 0;        //判断密码,如果3正确则flag=1
    int i = 0;
    if (argc == 3)       
    {
        for (i=0; i<MAXSIZE_USER; i++)
        {
        	if (strcmp(user_account[i], argv[1]) == 0 && strcmp(user_password[i], argv[2]) == 0)
        	{
        		flag=1;
        	}
        }
        if (flag)
        {
        	printf("登入成功!\n");
        }
        else
        {
        	printf("密码错误!\n");
        	_exit(0);
        }
    }
    else
    {
    	printf("密码错误!\n");
    	_exit(0);
    }
    
    int input = 0;
    int ExitSystem = 1;
    do
    {
    	Menu();
    	scanf("%d",&input);
    	switch (input)
    	{
    		case 0:
    		    Fuc_FindBook(books);   //查询功能
    		        break;
    		case 1:
                Fuc_AddBook(books);  //增加书籍功能；判断是否存在该书，有，则数量加一
                                                        //没有，则添加该书目
    		        break;
    		case 2:
    		    Fuc_DelBook(books);  //删除旧书功能
    		        break;
    		case 3:
    		    Fuc_ReturnBook(books);  //书在册，则数量加一，不存在，则新增书目
    		        break;
    		case 4:
    		    Fuc_BookList(books);   //打印图书列表
    		        break;
    		case 5:
    		        ExitSystem = 0;
    		        break;
    	}
    }while(ExitSystem);
    
	return 0;
}