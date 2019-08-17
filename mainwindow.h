#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

struct key
{
    int zhan=0;
    bool l=0,r=0,u=0,d=0;
};

struct jing_game
{
    key map[5][5];
    bool turn=0;
    int winner=0;
    void modify(int x,int y)
    {
        map[x][y].zhan=turn+1;
        if(map[x-1][y].zhan==map[x][y].zhan&&map[x][y].zhan==map[x+1][y].zhan)winner=turn+1;
        if(map[x][y-1].zhan==map[x][y].zhan&&map[x][y].zhan==map[x][y+1].zhan)winner=turn+1;
        if(y<2&&map[x][y].zhan==map[x][y+1].zhan&&map[x][y].zhan==map[x][y+2].zhan)winner=turn+1;
        if(y>2&&map[x][y].zhan==map[x][y-1].zhan&&map[x][y].zhan==map[x][y-2].zhan)winner=turn+1;
        if(x<2&&map[x][y].zhan==map[x+1][y].zhan&&map[x][y].zhan==map[x+2][y].zhan)winner=turn+1;
        if(x>2&&map[x][y].zhan==map[x-1][y].zhan&&map[x][y].zhan==map[x-2][y].zhan)winner=turn+1;
        if(x>2&&y>2&&map[x][y].zhan==map[x-1][y-1].zhan&&map[x][y].zhan==map[x-2][y-2].zhan)winner=turn+1;
        if(x>2&&y<2&&map[x][y].zhan==map[x-1][y+1].zhan&&map[x][y].zhan==map[x-2][y+2].zhan)winner=turn+1;
        if(x<2&&y<2&&map[x][y].zhan==map[x+1][y+1].zhan&&map[x][y].zhan==map[x+2][y+2].zhan)winner=turn+1;
        if(x<2&&y>2&&map[x][y].zhan==map[x+1][y-1].zhan&&map[x][y].zhan==map[x+2][y-2].zhan)winner=turn+1;
        if(x==2&&y==2&&map[x+1][y+1].zhan==map[x][y].zhan&&map[x][y].zhan==map[x-1][y-1].zhan)winner=turn+1;
        if(x==2&&y==2&&map[x-1][y+1].zhan==map[x][y].zhan&&map[x][y].zhan==map[x+1][y-1].zhan)winner=turn+1;
        turn=!turn;
        return;
    }
};
struct AI
{
    int val[270010],x[270010],y[270010],to[270010];
    int m[5][5];
    int mark(int x,int y)
    {
        return 2*(3*x+y-4);
    }
    /*
    void print(int tmp)
    {
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cout<<((tmp&(3<<mark(i,j)))>>mark(i,j))<<" ";
            }
            cout<<endl;
        }
        return;
    }
    */
    bool check(int tmp,int x,int y)
    {
        int m[5][5];
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                m[i][j]=(tmp&(3<<mark(i,j)))>>mark(i,j);
            }
        }
        if(m[x-1][y]==1&&1==m[x+1][y])return 1;
        if(m[x][y-1]==1&&1==m[x][y+1])return 1;
        if(y<2&&1==m[x][y+1]&&1==m[x][y+2])return 1;
        if(y>2&&1==m[x][y-1]&&1==m[x][y-2])return 1;
        if(x<2&&1==m[x+1][y]&&1==m[x+2][y])return 1;
        if(x>2&&1==m[x-1][y]&&1==m[x-2][y])return 1;
        if(x>2&&y>2&&1==m[x-1][y-1]&&1==m[x-2][y-2])return 1;
        if(x>2&&y<2&&1==m[x-1][y+1]&&1==m[x-2][y+2])return 1;
        if(x<2&&y<2&&1==m[x+1][y+1]&&1==m[x+2][y+2])return 1;
        if(x<2&&y>2&&1==m[x+1][y-1]&&1==m[x+2][y-2])return 1;
        if(x==2&&y==2&&m[x+1][y+1]==1&&1==m[x-1][y-1])return 1;
        if(x==2&&y==2&&m[x-1][y+1]==1&&1==m[x+1][y-1])return 1;
        return 0;
    }
    int roll(int tmp)
    {
        int ans=0;
        for(int i=0;i<=16;i+=2)
        {
            if(((tmp&(3<<i))>>i)==0)continue;
            if((tmp&(3<<i))>>i==1)ans|=(2<<i);
            else ans|=(1<<i);
        }
        return ans;
    }
    int DFS(int at)
    {
        if(val[at]!=-2)return val[at];
        int tmp,tat,tval;
        bool flag=0;
        for(int i=1;i<=3;i++)
        {
            for(int j=1;j<=3;j++)
            {
                tmp=mark(i,j);
                if((at&(3<<tmp))>>tmp==1||(at&(3<<tmp))>>tmp==2)continue;
                flag=1;
                tat=at|(1<<tmp);
                if(check(tat,i,j))tval=1;
                else tval=-DFS(roll(tat));
                if(val[at]<tval)
                {
                    val[at]=tval;
                    x[at]=i;
                    y[at]=j;
                    to[at]=tat;
                }
            }
        }
        if(!flag)val[at]=0;
        return val[at];
    }
    void get_qipu()
    {
        for(int i=0;i<=270000;i++)
        {
            val[i]=-2;
            x[i]=0;
            y[i]=0;
        }
        DFS(0);
        return;
    }
};
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void AI_do(int at);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
