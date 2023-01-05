#include "head.h"


void Fuc_Add_Newbook(writting Book)    //添加新书(书名、作者、数量、价格)
{
    getchar();
    book* b = (book*)malloc(sizeof(book));
    printf("请输入新书的名字>");
    scanf("%[^\n]", b->bookname);
    strcpy(Book[len].bookname, b->bookname);
    //printf("qwer2\n");
    getchar();

    printf("请输入作者>");
    scanf("%[^\n]", b->writer);
    strcpy(Book[len].writer, b->writer);
    //printf("qwer3\n");
    getchar();
    
    printf("请输入单价>");
    scanf("%f", &(Book[len].price));
    //printf("qwer4\n");
    getchar();
    
    Book[len].id = len + 1;
    Book[len].num += 1;
    free(b);
    
    //printf("len++=%d\n",len);
    printf("\n编号:%d\n书名:%s\n作者:%s\n数量:%d\n价格:%.2f\n\n"
        , Book[len].id, Book[len].bookname, Book[len].writer
        , Book[len].num, Book[len].price);

    len++;
}

void Fuc_FindBook_BookName(writting Book, char* name)   //输入书名查询
{
    int i = 0, flag = 0;
    for (i=0; i<len; i++)
    {
        if (strcmp(Book[i].bookname, name) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        printf("\n编号:%d\n书名:%s\n作者:%s\n数量:%d\n价格:%.2f\n\n", Book[i].id
                  , Book[i].bookname, Book[i].writer, Book[i].num, Book[i].price);
        Fuc_FindBook_Borrow( Book, i); //还书功能
    }
    else
    {
        printf("输入错误!\n");
    }
}

void Fuc_FindBook_BookWriter(writting Book, char* name) //输入作者查询
{
    int i = 0, flag = 0;

    for (i=0; i<len; i++)
    {
        if (strcmp(Book[i].writer, name) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        printf("\n编号:%d\n书名:%s\n作者:%s\n数量:%d\n价格:%.2f\n\n", Book[i].id
                  , Book[i].bookname, Book[i].writer, Book[i].num, Book[i].price);
        Fuc_FindBook_Borrow( Book, i);  //还书功能
    }
    else
    {
        printf("输入错误!\n");
    }
}

void Fuc_FindBook_BookId(writting Book, int id)  //输入编号查询
{
    int i = 0, flag = 0;

    for (i=0; i<len; i++)
    {
        if (Book[i].id == id)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        printf("\n编号:%d\n书名:%s\n作者:%s\n数量:%d\n价格:%.2f\n\n", Book[i].id
                  , Book[i].bookname, Book[i].writer, Book[i].num, Book[i].price);
        Fuc_FindBook_Borrow( Book, i);  //还书功能
    }
    else
    {
        printf("输入错误!\n");
    }
}

void Fuc_FindBook_Borrow(writting Book, int i)   //还书功能
{
    int input = 0;
    int exit = 1;

    do
    {
        getchar();              //清除缓存区
        printf("1.借阅\t0.返回\t\n");
        scanf("%d",&input);

        if (input == 1 && Book[i].num > 0)
        {
            (Book[i].num)--;
            printf("\n编号:%d\n书名:%s\n作者:%s\n数量:%d\n价格:%.2f\n\n", Book[i].id
                  , Book[i].bookname, Book[i].writer, Book[i].num, Book[i].price);
        }
        else if (input == 0)
        {
            exit = 0;
        }
        else
        {
            printf("输入错误,请重试!\n");
        }
    }while(exit);
}

void Menu()     //主菜单
{
    printf("******************************\n");
    printf("         图书管理系统   \n");
    printf("   0. 查询(书名 作者 编号)\n");
    printf("   1. 增加新书\n");
    printf("   2. 删除旧书\n");
    printf("   3. 还书\n");
    printf("   4. 打印图书列表\n");
    printf("   5. 退出\n");
    printf("******************************\n");
}

void Menu_FindBook()    //查询菜单
{
    printf("\n-----------查询-----------\n");
    printf("0 书名\n");
    printf("1 作者\n");
    printf("2 编号\n");
    printf("3 返回主菜单\n");   
}

void Fuc_FindBook(writting Bookname)  //查询功能
{
    int input = 999;
    int exit_FindBook = 1;
    
    do
    {
        book* b = (book*)malloc(sizeof(book));
        Menu_FindBook();    //查询菜单
        printf("请输入需要查询的内容>");
        scanf("%d",&input);
        getchar();
        switch (input)
        {
            case 0 :
            printf("请输入书名>");
            scanf("%[^\n]",b->bookname);
            Fuc_FindBook_BookName( Bookname, b->bookname);  //输入书名查询
            free(b);
                    break;
            case 1 :
            printf("请输入作者>");
            scanf("%[^\n]",b->writer);
            Fuc_FindBook_BookWriter( Bookname, b->writer); //输入作者查询
            free(b);
                    break;
            case 2 :
            printf("请输入编号>");
            scanf("%d",&(b->id));
            Fuc_FindBook_BookId(Bookname, b->id); //输入编号查询
            free(b);
                    break;
            case 3 :
                    exit_FindBook = 0;
                    break;
            default :
            printf("输入错误!\n");
        }
    }while(exit_FindBook);
}

void Fuc_AddBook(writting Book)  //增加书籍功能；判断是否存在该书，有，则数量加一
                             //没有，则添加该书目
{
    int input = 1, exit = 1, flag = 0;
    getchar();
    do
    {
        int i = 0;
        book* b = (book*)malloc(sizeof(book));
        printf("\n请输入新增的图书信息(名称)>");
        scanf("%[^\n]", b->bookname);
        getchar();
        for (i = 0; i<len; i++ )
        {
            if (strcmp(Book[i].bookname, b->bookname) == 0)
            {
                flag = 1;
                Book[i].num++;
                break;
            }
        }
        if (flag)
        {
            printf("\n编号:%d\n书名:%s\n作者:%s\n数量:%d\n价格:%.2f\n\n"
                , Book[i].id, Book[i].bookname, Book[i].writer
                , Book[i].num, Book[i].price);
            free(b);
        }
        else
        {
            free(b);
            printf("是未收录的书!\n");
            Fuc_Add_Newbook(Book);     //添加新书(书名、作者、数量、价格)
        }

        printf("\t1.继续\t2.退出\t\n");
        scanf("%d",&input);
        getchar();
        while (1)
        {
            if (input == 1)
            {
                break;
            }
            else if (input == 2)
            {
                exit = 0;
                break;
            }
            else
            {
                printf("输入错误,请重新输入!\n");
                printf("\t1.继续\t2.退出>\t\n");
                scanf("%d",&input);
                getchar();
            }
        }
    }while(exit);
}

void Menu_DelBook()    //删除旧书菜单
{
    printf("0.书名   \n");
    printf("1.作者   \n");
    printf("2.编号   \n");
    printf("输入图书信息>");
}

void Fuc_DelBook_IsDelete(writting Book, int flag, int i)//删除旧书，
                                                        //并显示当前编号信息
{
    if (flag)
    {
        int j = 0;
        for (j = i; j<len; j++)
        {
            Book[j].id = (Book[j+1].id)-1;
            //printf("Book[j=%d].id=%d, Book[j=%d].id=%d\n", j , Book[j].id, j+1, Book[j+1].id);
            strcpy(Book[j].bookname, Book[j+1].bookname);
            strcpy(Book[j].writer, Book[j+1].writer);
            Book[j].num = Book[j+1].num;
            Book[j].price = Book[j+1].price;
        }

        printf("\n----------------------\n");
        printf("当前该位置的书籍信息:\n编号:%d\n书名:%s\n作者:%s\n数量:%d\n价格:%.2f\n", Book[i].id
      , Book[i].bookname, Book[i].writer, Book[i].num, Book[i].price);
        printf("----------------------\n\n");

        len--;
    }
    else
    {
        printf("图书不存在!\n");
    }
}

void Fuc_DelBook(writting Book)    //删除旧书功能
{
    int input = 1, exit = 1, flag = 0;

    do
    {
        book* b = (book*)malloc(sizeof(book));
        int i = 0;

        Menu_DelBook();
        scanf("%d", &input);
        getchar();

        switch (input)
        {
        case 0:
            printf("请输入删除的图书信息(书名)>");
            scanf("%[^\n]", b->bookname);
            //getchar();

            for (i = 0; i<len; i++ )
            {
                if (strcmp(Book[i].bookname, b->bookname) == 0)
                {
                    flag = 1;
                    break;
                }
            }
            free(b);
            Fuc_DelBook_IsDelete(Book, flag, i);  //删除旧书，并显示当前编号信息
            break;
        case 1:
            printf("请输入删除的图书信息(作者)>");
            scanf("%[^\n]", b->writer);
            //getchar();

            for (i = 0; i<len; i++ )
            {
                if (strcmp(Book[i].writer, b->writer) == 0)
                {
                    flag = 1;
                    break;
                }
            free(b);
            Fuc_DelBook_IsDelete(Book, flag, i); //删除旧书，并显示当前编号信息
            }
            break;
        case 2:
            printf("请输入删除的图书信息(编号)>");
            scanf("%d", &(b->id));
            getchar();

            for (i = 0; i<len; i++ )
            {
                if (Book[i].id == b->id)
                {
                    flag = 1;
                    break;
                }
            }  
            free(b);
            Fuc_DelBook_IsDelete(Book, flag, i); //删除旧书，并显示当前编号信息
            break;
        default:
        {
            printf("输入错误!\n"); 
        }     
        }

        while (1)
        {
            printf("1.继续\t2.退出\t\n");
            scanf("%d",&input);
            getchar();
            if (input == 1)
            {
                break;
            }
            else if (input == 2)
            {
                exit = 0;
                break;
            }
            else
            {
                printf("输入错误,请重新输入!\n");
                printf("\t1.继续\t2.退出\t\n");
                scanf("%d",&input);
                getchar();
            }
        }
    }while(exit);
}

void Menu_ReturnBook()  //还书菜单
{
    printf("0.书名   \n");
    printf("1.作者   \n");
    printf("2.编号   \n");
    printf("3.退出   \n");
    printf("选择输入图书信息>");
}

void Fuc_ReturnBook_IsExist_bookname(writting Book) //输入书名还书
{
    int flag = 0, i = 0;
    book* b = (book*)malloc(sizeof(book));

    printf("请输入归还的图书信息(书名)>");
    scanf("%[\n]", b->bookname);
    getchar();
    for (i = 0; i<len; i++ )
    {
        if (strcmp(Book[i].bookname, b->bookname) == 0)
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        b->num++;
        free(b);
    }
    else
    {
        free(b);
        printf("是未收录的新书\n");
        Fuc_Add_Newbook(Book);     //添加新书(书名、作者、数量、价格)
        printf("已扩充该书!\n");
    }
}

void Fuc_ReturnBook_IsExist_writer(writting Book) //输入作者还书
{
    int flag = 0, i = 0;
    book* b = (book*)malloc(sizeof(book));

    printf("请输入归还的图书信息(作者)>");
    scanf("%[\n]", b->writer);
    getchar();
    for (i = 0; i<len; i++ )
    {
        if (strcmp(Book[i].writer, b->writer) == 0)
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        b->num++;
        free(b);
    }
    else
    {
        free(b);
        printf("是未收录的新书,需要登记详细信息\n");
        Fuc_Add_Newbook(Book);     //添加新书(书名、作者、数量、价格)
        printf("已扩充该书!\n");
    }
}

void Fuc_ReturnBook_IsExist_id(writting Book)  //输入编号还书
{
    int flag = 0, i = 0;
    book* b = (book*)malloc(sizeof(book));

    printf("请输入归还的图书信息(编号)>");
    scanf("%d", &(b->id));
    getchar();
    for (i = 0; i<len; i++ )
    {
        if ( Book[i].id == b->id)
        {
            flag = 1;
            break;
        }
    }

    if (flag)
    {
        b->num++;
        free(b);
    }
    else
    {
        free(b);
        printf("是未收录的新书,需要登记详细信息\n");
        Fuc_Add_Newbook(Book);    //添加新书(书名、作者、数量、价格)
        printf("已扩充该书!\n");
    }
}

void Fuc_ReturnBook(writting Book) //书在册，则数量加一，不存在，则新增书目
{
    int input = 0, exit = 1;
    do
     {
        Menu_ReturnBook();  //打印还书菜单
        scanf("%d", &input);
        getchar();

        switch (input)
        {
        case 0:
                Fuc_ReturnBook_IsExist_bookname( Book); //输入书名还书
                break;
        case 1:
                Fuc_ReturnBook_IsExist_writer( Book);   //输入作者还书
                break;
        case 2: 
                Fuc_ReturnBook_IsExist_id( Book);  //输入编号还书
                break;
        case 3:
                exit = 0;
                break;
        default:
                printf("输入错误,请重新输出!\n");
        }

        while (1)
        {
            printf("1.继续\t2.退出\t\n");
            scanf("%d",&input);
            getchar();
            if (input == 1)
            {
                break;
            }
            else if (input == 2)
            {
                exit = 0;
                break;
            }
            else
            {
                printf("输入错误,请重新输入!\n");
                printf("\t1.继续\t2.退出\t\n");
                scanf("%d",&input);
                getchar();
            }
        };
     } while (exit); 
}

void print_(int n)  //分割线
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("-");
    }
    printf("\n");
}

void Fuc_BookList_format(writting Book) //书籍信息对齐
{
    int i = 0;
    printf("编号\t书名\t\t\t\t作者:\t\t\t\t数量\t价格\n");
    for (i = 0; i < len; i++)
    {
        if (strlen(Book[i].bookname) > 0 && strlen(Book[i].bookname)<=8)
        {
            if (strlen(Book[i].writer) > 0 && strlen(Book[i].writer)<=8)
            {
                printf("%d\t%s\t\t\t\t%s\t\t\t\t%d\t%.2f\n", Book[i].id, Book[i].bookname
                , Book[i].writer, Book[i].num, Book[i].price);
            }
            else if (strlen(Book[i].writer) > 8 && strlen(Book[i].writer)<=16)
            {
                printf("%d\t%s\t\t\t\t%s\t\t\t%d\t%.2f\n", Book[i].id, Book[i].bookname
                , Book[i].writer, Book[i].num, Book[i].price);
            }
            else if (strlen(Book[i].writer) > 16 && strlen(Book[i].writer)<=24)
            {
                printf("%d\t%s\t\t\t\t%s\t\t%d\t%.2f\n", Book[i].id, Book[i].bookname
                , Book[i].writer, Book[i].num, Book[i].price);
            }
            else
            {
                printf("%d\t%s\t\t\t\t%s\t%d\t%.2f\n", Book[i].id, Book[i].bookname
                , Book[i].writer, Book[i].num, Book[i].price);   
            }
        }
        else if (strlen(Book[i].bookname) > 8 && strlen(Book[i].bookname)<=16)
        {
            if (strlen(Book[i].writer) > 0 && strlen(Book[i].writer)<=8)
            {
                printf("%d\t%s\t\t\t%s\t\t\t\t%d\t%.2f\n", Book[i].id, Book[i].bookname
                , Book[i].writer, Book[i].num, Book[i].price);
            }
            else if (strlen(Book[i].writer) > 8 && strlen(Book[i].writer)<=16)
            {
                printf("%d\t%s\t\t\t%s\t\t\t%d\t%.2f\n", Book[i].id, Book[i].bookname
                , Book[i].writer, Book[i].num, Book[i].price);
            }
            else if (strlen(Book[i].writer) > 16 && strlen(Book[i].writer)<=24)
            {
                printf("%d\t%s\t\t\t%s\t\t%d\t%.2f\n", Book[i].id, Book[i].bookname
                , Book[i].writer, Book[i].num, Book[i].price);
            }
            else
            {
                printf("%d\t%s\t\t\t%s\t%d\t%.2f\n", Book[i].id, Book[i].bookname
                , Book[i].writer, Book[i].num, Book[i].price);   
            }            
        }
        else if (strlen(Book[i].bookname) > 16 && strlen(Book[i].bookname)<=24)
        {
            if (strlen(Book[i].writer) > 0 && strlen(Book[i].writer)<=8)
            {
                printf("%d\t%s\t\t%s\t\t\t\t%d\t%.2f\n", Book[i].id, Book[i].bookname
                , Book[i].writer, Book[i].num, Book[i].price);
            }
            else if (strlen(Book[i].writer) > 8 && strlen(Book[i].writer)<=16)
            {
                printf("%d\t%s\t\t%s\t\t\t%d\t%.2f\n", Book[i].id, Book[i].bookname
                , Book[i].writer, Book[i].num, Book[i].price);
            }
            else if (strlen(Book[i].writer) > 16 && strlen(Book[i].writer)<=24)
            {
                printf("%d\t%s\t\t%s\t\t%d\t%.2f\n", Book[i].id, Book[i].bookname
                , Book[i].writer, Book[i].num, Book[i].price);
            }
            else
            {
                printf("%d\t%s\t\t%s\t%d\t%.2f\n", Book[i].id, Book[i].bookname
                , Book[i].writer, Book[i].num, Book[i].price);   
            }            
        }
        else
        {
            if (strlen(Book[i].writer) > 0 && strlen(Book[i].writer)<=8)
            {
                printf("%d\t%s\t%s\t\t\t\t%d\t%.2f\n", Book[i].id, Book[i].bookname
                , Book[i].writer, Book[i].num, Book[i].price);
            }
            else if (strlen(Book[i].writer) > 8 && strlen(Book[i].writer)<=16)
            {
                printf("%d\t%s\t%s\t\t\t%d\t%.2f\n", Book[i].id, Book[i].bookname
                , Book[i].writer, Book[i].num, Book[i].price);
            }
            else if (strlen(Book[i].writer) > 16 && strlen(Book[i].writer)<=24)
            {
                printf("%d\t%s\t%s\t\t%d\t%.2f\n", Book[i].id, Book[i].bookname
                , Book[i].writer, Book[i].num, Book[i].price);
            }
            else
            {
                printf("%d\t%s\t%s\t%d\t%.2f\n", Book[i].id, Book[i].bookname
                , Book[i].writer, Book[i].num, Book[i].price);   
            }            
        }
    }        
}

void Fuc_BookList(writting Book)   //打印图书列表
{
    int n = 95, input = 0, flag = 1;
    print_(n);  //分割线
    Fuc_BookList_format(Book);  //书籍信息对齐
    print_(n);  //分割线

    do
    {
        printf("1.退出\n");
        scanf("%d",&input);
        getchar();
        if ( input == 1)
        {
            flag = 0;
        }
        else
        {
            printf("输入错误,请重新选择!\n");
        }
    }while (flag);
}

