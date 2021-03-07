#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <random>
#include <fstream>

#pragma comment (lib, "winmm.lib")

using namespace std;

random_device rd;
mt19937 gen(rd());
string a[900][900] , C[20];
int g,w=0,z[30] ,u=0,checksavee=0, x ,
  y[20] ,I=0 ,winer , py[30]  , px[30] ,
  mx[30],my[30] ,Round, chance ,Dmove , row[20] ,
  Move[20] ,save[500][20] ,con ,fini=50, pointer , k=0 ,
  movefake[20]  , moveorg[20] , dif ,v , b , f ,e=22, l , sn ,
  we=0 ,poys[30][30] ,poxs[30][30] ,poye[30][30],poxe[30][30];
struct player {
    char name[100];
    char nickname[1];
};

player s[20];

void debug(int m , int n) {
    cout<<m<<" "<<n;
   /*
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m * (n + 1); j++) {
            cout << i << "," << j << "=" << a[i][j] << "/ ";
        }
        cout << endl;
    }
    */
    cout << endl;
    for (int k = 1; k <= n; k++) {
        cout << "name player (" << k << ") :" << s[k].name << " nickname :" << C[k] << "  /  ";
        cout << "row = " << row[k] << " move = " << Move[k] << " pointer= " << pointer << " move original= "
             << moveorg[k] << endl;
    }
    cout << endl;
    cout<<"ladders positions \n";
    for(int i=1 ; i<=l ; i++){
        cout<<py[i]<<","<<px[i]<<"/";
    }
    cout<<"\n badane pele "<<z[1]<<" "<<z[10];

    cout<<"\n snakes positions \n";
    for(int i=1 ; i<=sn ; i++){
        cout<<my[i]<<","<<mx[i]<<"/";
    }
    for(int i=1 ; i<=sn-1 ;i++){
        cout<<'\n'<<mx[i]-z[2]-2;
        cout<<'\n'<<mx[i]-z[20]-2;
    }
    cout<<"\n badane mar "<<z[2]<<" "<<z[20];


}

void color (int i){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,i);
}

void space (){
    cout<<"\t\t\t\t\t\t\t\t\t\t";
}

void Hello (){
    Sleep(150);
    space();
    system("color 0A");
    cout<<"Hello , World !\r";
    Sleep(100);
    cout<<"                                                                             \r";
    cout<<endl<<endl<<endl;
    system("color C9");
    Sleep(100);
    system("color 9C");
    Sleep(100);
    system("color 0A");
    space();
    cout<<"  <-snakes-> \r";
    Sleep(500);
    space();
    cout<<"                   \r";
    space();
    cout<<"       &\r";
    Sleep(500);
    space();
    cout<<'\r';
    space();
    cout<<"  #ladders#\r";
    Sleep(500);
    space();
    cout<<'\r';
    space();
    cout<<"\n\n\n\n\n\n\n\n";
    system("cls");
    space();
    cout <<" press any key to start the game [---] \n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    getch();
    Sleep(500);

}

void load(){

    cout<<"\t\t\t\t\t\t\t\t\t\t\t\tloading ...\r";
    Sleep(340);
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t                     \r";
    for(int i=0 ; i<=100 ; i++){
        color(i);
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t"<<i<<"%"<<'\r';
        Sleep(15);
        color(0);
        cout<<"\t\t\t\t\t\t\t\t\t\t\t\t   \r";
    }
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t       \r";
}

void waiting(){
    cout<<endl<<endl<<endl<<endl<<endl;
    system("color 0C");
    space();
    cout<<"please wait"<<endl;
    space();
    Sleep(600);
    cout<<".";
    Sleep(600);
    cout<<".";
    Sleep(600);
    cout<<".";
    Sleep(600);
    cout<<"."<<endl;
    system("color 03");
}

void map(int m , int n ) {
    int c = 0;
    space();
    for (int j = 1; j <= m; j++) {
        color(12);
        cout << "*";
        if (j < 10) {
            if (n % 2 == 0) {
                for (int i = 1; i <= n / 2; i++) {
                    cout << " ";
                }
                cout << j;
                for (int x = 1; x <= n / 2; x++) {
                    cout << " ";
                }

            } else {
                cout << " " << j;
                for (int i = 1; i <= n - 1; i++) {
                    cout << " ";
                }
            }
        }
        if (j >= 10) {
            cout << j;
            for (int i = 1; i <= n - 1; i++)
                cout << " ";
        }

    }
    cout << "*" << endl;
    for (int i = m; i >= 1; i--) {
        color(13);
        if (i >= 10) {
            cout << "                                                                              ";
        } else {
            cout << "                                                                               ";
        }
        cout << i;
        for (int j = 1; j <= m; j++) {
            color(9);
            cout << "|";
            if (c == (n + 1) * (m)) {
                c = 0;
            }

            for (int k = c + 1; k <= c + (n + 1); k++) {
                int h=4;
                color(15);
                for (int y = 1; y <= n; y++) {
                    if (i == row[y] and k == moveorg[y]) {
                        color(y + 9);
                        cout << a[i][k];
                        h=0;
                    }
                }
                if(h!=0){
                    color(15);
                    cout << a[i][k];
                }

            }
            c = c + n + 1;
        }
        color(9);
        cout << "|" << endl;
        space();
        color(11);
        for (int l = 1; l <= m + 1; l++) {
            cout << "*";
            if (l != m + 1) {
                for (int j = 1; j <= n + 1; j++) {
                    cout << "-";
                }
            }
        }
        //Sleep(200);
        cout << endl;


    }
}

void dice(int i , int o) {
    uniform_real_distribution<double> col(1.00, 14.32);
    color((int)col(gen));
    if(w==0){
        space() ;
        cout << s[i].name << " your turn !  press any key for using dice " << endl;
        if(i==1 and o!=1 and o!=2 )
            getch();
        getch();
    }
    uniform_real_distribution<double> dic(1.00, 6.98);
    chance=(int)dic(gen);
    color((int)col(gen));
    space();
    cout << "your dice number is " << chance << endl;
    space();
    cout << "now you have " << chance << " movement !" ;
    cout<<" .";
    Sleep(300);
    cout<<".";
    Sleep(300);
    cout<<".";
    Sleep(400);
    cout<<".\n";
    w++ ;
    Sleep(150);
}

void win(int m , int n , int j) {
    color(j+8);
    if (pointer >= m * 100 + m * (n + 1) - n) {
        g = 50;
        space();
        cout << s[j].name << endl ;
        space();
        cout<< "    you win " << endl;
        space();
        cout << "do you want to continue ? yes=1 no=0";
        cin >> g;
        y[j] = j;
        if(I==0){
            winer=j;
        }
        I++;
    }

}

void calculating(int m , int n) {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m * (n + 1); j++) {
            a[i][j] = " ";
        }
    }
    a[1][1]="S";
    a[1][2]="T";
    a[1][3]="R";
    a[m][m*(n+1)-2]="E";
    a[m][m*(n+1)-1]="N";
    a[m][m*(n+1)]="D";
    int h=0;
    for (int i = 1; i <= 19; i++) {
        row[i] = 1;
        moveorg[i] = n-h;
        Move[i] = 1;
        movefake[i] = 0;
        y[i]=0;
        py[i]=0;
        px[i]=0;
        mx[i]=0;
        my[i]=0;
        if(n!=h)
            h++;

    }
}

void think (int j , int m) {
    b=40 ;
    g=50 ;
    Dmove=50;
    if (m * m - Move[j] < chance) {
        space();
        cout<<"Mmm ... let me think *___* ";
        Sleep(200);
        cout<<".";
        Sleep(200);
        cout<<".";
        Sleep(200);
        cout<<".";
        Sleep(200);
        cout<<".\n";
        space();
        cout << "sorry you cant move :(" << endl;
        if(chance!=6)
            g = 0;
        else
            b=0 ;
    }

}

void playerinfo (int n) {
    cout<<endl;
    space();
    color(116);
    cout  << "now ! ... please tell me your names:" << endl;
    for (int i = 1; i <= n; i++) {
        do{
            color(i+9);
            space();
            cout << "player (" << i << "): enter your name :" << endl;
            cin >> s[i].name;
            space();
            cout << "now use A letter to be your nickname on the map :) " << endl;
            cin >> s[i].nickname;
            space();
            cout << "are you sure for " << s[i].name << " as your name and " << s[i].nickname << " as your nickname ?"<< endl;
            space();
            cout<< "yes =1 no=0" << endl;
            cin >> g;
        }
        while(g==0);

        a[1][i] = s[i].nickname;
    }
    for (int i = 1; i <= n; i++) {
        C[i] = a[1][i];
    }

}

void random (int m) {
//---------------------------------- PELE -----------------
    int h = 3, h1 = 3;
    for (int i = 1; i <= l - 1; i++) {
        do {
            uniform_real_distribution<double> dist(m/2 + 1 + 0.0, m + 0.30);
            py[i] = (int) dist(gen);
            if (i == l - 1) {
                for (int k = 1; k <= l - 1; k++) {
                    for (int j = 1; j <= l - 1; j++) {
                        if (k != j) {
                            if (py[k] == py[j])
                                h = 1;
                            else
                                h1 = 0;
                        }
                    }
                }
            }
        } while (h == 1 and h1!=0);
        h = 3 ; h1 = 3;
        do {
            uniform_real_distribution<double> dist1(1.00, m -2 +0.33);
            px[i] = (int) dist1(gen);
            if (i == l - 1) {
                for (int k = 1; k <= l - 1; k++) {
                    for (int j = 1; j <= l - 1; j++) {
                        if (k != j) {
                            if (px[k] == px[j]) {
                                h = 1;
                            } else
                                h1 = 0;
                        }
                    }
                }
            }
        } while (h == 1 and h1!=0);
    }
//--------------badane pele -------------------------------
    if (m >= 10) {
            int max=(m/2)+1 ;
        do {
            uniform_real_distribution<double> dist(4.00, max+0.34);
            z[1] = (int) dist(gen);
            z[10] = (int) dist(gen);
        } while (z[1] == z[10]);
    }
    if (m < 10) {
        do {
            uniform_real_distribution<double> dist(2.00, 4.30);
            z[1] = (int) dist(gen);
            z[10] = (int) dist(gen);
        } while (z[1] == z[10]);
    }
    //--------------badane mar ------------------------------
    if (m >= 10) {
        int  max=(m/2)-1 ;
        do {
            uniform_real_distribution<double> dist(2.00, max+0.33);
            z[2] = (int) dist(gen);
            z[20] = (int) dist(gen);
        } while (z[2] == z[20]);
    }
    if (m < 10) {
        do {
            uniform_real_distribution<double> dist(1.0, 2.33);
            z[2] = (int) dist(gen);
            z[20] = (int) dist(gen);
        } while (z[2] == z[20]);
    }

//-------------------- mokhtasat sar mar 3 4 ------------------------
    h = 3;
    h1 = 3;
    int c=1;
    do {
        for (int i = 1; i <= sn - 1; i++) {
            do {
                if (m < 10) {
                    uniform_real_distribution<double> dist(m - 2 + 0.0, m - 1 + 0.30);
                    my[i] = (int) dist(gen);
                }
                if (m >= 10) {
                    uniform_real_distribution<double> dist(m/2 +1 + 0.0, m - 1 + 0.30);
                    my[i] = (int) dist(gen);
                }
            } while (i != 1 and my[i] == my[i - 1]);
            do {
                uniform_real_distribution<double> dist(m/2 + 0.0, m + 0.30);
                mx[i] = (int) dist(gen);
                if (i == sn - 1) {
                    for (int k = 1; k <= sn - 1; k++) {
                        for (int j = 1; j <= sn - 1; j++) {
                            if (k != j) {
                                if (mx[k] == mx[j]) {
                                    h = 1;
                                } else
                                    h1 = 0;
                            }
                        }
                    }
                }
                if((1> mx[i]-z[2]-2 and 1>mx[i]-z[20]-2)){
                    c=0;
                }

            } while ((h == 1 and h1!=0) or (mx[i] == m - 4 and my[i] == m - 3) or c==0);

        }
        h=3 ;h1=3;
        for (int i = 1; i <= sn - 1; i++) {
            for (int j = 1; j <= l - 1; j++) {
                if ((my[i] - z[2] == py[j] or my[i] - z[20] == py[j]) and (mx[i] - z[2] == px[j] or mx[i] - z[20] == px[j]) or (my[i] == py[j] and mx[i] == px[j]))
                    h = 1;
                else
                    h1 = 0;
            }
        }
    } while (h == 1 and h1!=0);
}

void ladders (int m , int dif){
    if (dif == 1) {
        l=m/2 ;
    }
    if (dif == 2) {
        if(m % 2 ==0)
            l=m-(m/2)-1 ;
        else
            l=m-m/2 ;

    }
}

void snakes (int m  , int dif){
    if (dif == 1) {
        sn=m-(m/2)-1 ;
    }
    if (dif == 2) {
        if(m % 2==0)
            sn=m/2 ;
        else
            sn=(m/2) -1 ;

    }
}

void emptymap (int m , int n ) {
    //------------------------------------spaces--------------------------------------
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m * (n + 1); j++) {
            a[i][j] = " ";
        }
    }
    //------------------------------ladders--------------------------------
    //-----------------------------original ladder ------------------------
    if(z[1]>z[10])
        v=z[10];
    else
        v=z[1];
    for(int i=0 ; i<=v-1 ; i++){
        a[m-4-i][(m-(i))*(n+1)]="#";
    }
    //----------------------------random ladder---------------------------
    v=z[1];f=0;
    for(int i=1 ; i<=l-1 ; i++){
        for(int j=0 ; j<=v-1 ; j++){
            a[py[i]-(j)][(n+1)*px[i]-f]="#";
            if(j==0){
                poxe[1][i]=py[i]-(j);
                poye[1][i]=(n+1)*px[i];
            }
            if(j==v-1){
                poxs[1][i]=py[i]-(j);
                poys[1][i]=(n+1)*px[i];
            }
        }
        if(i % 2 ==1)
            v=z[10];
        else
            v=z[1];
        if(i%3==1)
            f=1;
        if(i%3==2)
            f=2;
        if(i%3==0)
            f=0;
    }
    //------------------------------snakes---------------------------------
    //---------------------- original snake  --------------------------------
    a[m][(m-1)*(n+1)]=">";
    a[m-1][(m-2)*(n+1)]="/";
    a[m-2][(m-3)*(n+1)]="/";
    a[m-3][(m-4)*(n+1)]="<";
    //-----------------------random snakes---------------------------------
    v=z[2];
    f=1;
    for(int i=1 ; i<=sn-1 ; i++){
        poxs[2][i]=my[i];
        poys[2][i]=mx[i]*(n+1);
        a[my[i]][mx[i]*(n+1)-f]=">";
        for(int j=1 ; j<=v ; j++){
            a[my[i]-j][(mx[i]-j)*(n+1)-f]="/";
        }
        a[my[i]-v-1][(mx[i]-v-1)*(n+1)-f]="<";
        poxe[2][i]=my[i]-v-1;
        poye[2][i]=(mx[i]-v-1)*(n+1);
        if(i % 2 ==1) {
            v = z[20];
            f=2;
        }
        else {
            v = z[2];
            f=1;
        }

    }



}

void pointmake( int j) {
    if (row[j] < 10 and moveorg[j] < 10) {
        pointer = row[j] * 10 + moveorg[j];

    }
    if (row[j] < 10 and moveorg[j] >= 10) {
        pointer = row[j] * 100 + moveorg[j];
    }
    if (row[j] >= 10 and moveorg[j] < 10) {
        pointer = row[j] * 10 + moveorg[j];

    }
    if (row[j] >= 10 and moveorg[j] >= 10) {
        pointer = row[j] * 100 + moveorg[j];

    }
}

void moving(int m , int n , int j) {
   if(u==0 and checksavee!=0){
       chance=0;
   for(int i=1 ; i<=n ; i++)
    moving(m , n ,i);
   u++;
   }
    int extrow;
    row[j] = 1;
    Move[j] = Move[j] + chance;
    if (Move[j] < m) {
        movefake[j] = Move[j];
    }
    if (Move[j] > m) {
        extrow = Move[j] / m;
        row[j] = row[j] + extrow;
        movefake[j] = Move[j] % m;
        if (movefake[j] == 0) {
            movefake[j] = m;
            row[j]--;
        }

    }
    if (Move[j] == m) {
        movefake[j] = m;
    }

    moveorg[j] = movefake[j] * (n + 1) - (n - k);
}

void Acheck(int j , int m , int n) {
    Move[j] = (row[j] - 1) * m + moveorg[j] / (n + 1) + 1;

    a[row[j]][moveorg[j]] = C[j];
    pointmake( j);
    for (int x = 1; x <= n; x++) {
        a[row[x]][moveorg[x]] = C[x];
    }
}

void check (int m , int n , int j , int k ) {
    //----------------checking ladders ------------------------------------------
    //--------------------ladder original---------------------
    if(z[1]>z[10])
        v=z[10];
    else
        v=z[1];
    if (row[j] == m-4-(v-1) and moveorg[j] == (n+1)*(m-(v-1))-(n-k)) {
        cout << endl ;
        space();
        cout<< "woo ! "<<s[j].name<<" Go Up There ;)" ;
        cout<<" .";
        Sleep(200);
        cout<<".";
        Sleep(200);
        cout<<".";
        Sleep(200);
        cout<<".\n";
        emptymap(m, n);
        row[j] = m-4;
        moveorg[j] = (n+1)*m-(n-k);
        Acheck(j, m, n);
        map(m, n );
    }
    //-----------------random ladders--------------------------
    for(int i=1 ; i<=l ; i++){
        if (row[j] == poxs[1][i]and moveorg[j] == poys[1][i]-(n-k)) {
            cout << endl ;
            space();
            cout<< "woo ! "<<s[j].name<<" Go Up There ;)" ;
            cout<<" .";
            Sleep(200);
            cout<<".";
            Sleep(200);
            cout<<".";
            Sleep(200);
            cout<<".\n";
            emptymap(m, n);
            row[j] = poxe[1][i];
            moveorg[j] = poye[1][i]-(n-k);
            Acheck(j, m, n);
            map(m, n );
        }
    }
    //------------------------checking snakes----------------------------------
// ---------------------------Random snakes----------------------------------
    for(int i=1 ; i<=sn ; i++){
        if (row[j] == poxs[2][i] and moveorg[j] == poys[2][i]-(n-k)) {
            cout << endl ;
            space();
            cout<< "Oow ! "<<s[j].name<<" Go Down There :(" ;
            cout<<" .";
            Sleep(200);
            cout<<".";
            Sleep(200);
            cout<<".";
            Sleep(200);
            cout<<".\n";
            emptymap(m, n);
            row[j] = poxe[2][i];
            moveorg[j] = poye[2][i]-(n-k);
            Acheck(j, m, n);
            map(m, n );
        }
    }
//------------------------original snake--------------------------------------
    if (row[j] == m and moveorg[j] == (m-1)*(n+1)-(n-k)) {
        cout << endl ;
        space();
        cout<< "oow ! "<<s[j].name<<" Go Down There :(";
        cout<<" .";
        Sleep(200);
        cout<<".";
        Sleep(200);
        cout<<".";
        Sleep(200);
        cout<<".\n";
        emptymap(m, n);
        row[j] = m-3;
        moveorg[j] = (m-4)*(n+1)-(n-k);
        Acheck(j, m, n);
        map(m, n );
    }


}

void difficulty(int m ) {
    color(12);
    dif = 0;
    do{
        space();
        cout << "now choose difficulty of your game  !" << endl ;
        space();
        cout<< "normal=1 , hard=2";
        cin >> dif;
        if (dif == 1) {
            ladders(m , dif);
            snakes(m , dif) ;
        }
        if (dif == 2) {
            ladders(m , dif);
            snakes(m , dif) ;
        }
        if(dif!=1 and dif!=2){
            cout << "what are you doing :/" << endl << "try again !";
        }
    }
    while(dif!=1 and dif!=2);
}

void Cload(int m , int n ){
    int checksave=0 , c;
    ifstream save ;
    save.open("saveplayer.txt");
    if(save.is_open()){
//--------------------checking save----------------------------
        save >>checksave;
        if(checksave==1){
            cout<<"you have save , do you want to load this ? Yes = Y , No = N";
            while(!(GetKeyState('Y') & 0x8000)){
                if((GetKeyState('N')& 0x8000)){
                    checksavee=0;
                    return;
                }
            }
            checksavee=1;
//-------------------------tedad afrad va jadval--------------------
            save>>m>>n;

//----------------------snakes and ladders-------------------------
            save>>l>>sn;
//------------------------ladders position-------------------------
            for(int i=1 ; i<=l-1 ; i++){
                save>>px[i]>>py[i];
            }
            save>>z[1]>>z[10];
//-----------------------snakes position-----------------------------------------
            for(int i=1 ; i<=sn-1 ; i++){
                save>>mx[i]>>my[i];
            }
            save>>z[2]>>z[20];
//------------------------player position------------------------
            for(int i=1 ; i<=n ; i++){
                save>>Move[i];
            }
//------------------------player info----------------------------------
            for(int i=1 ; i<=n ; i++){
                save>>s[i].name>>C[i];
            }
        }
        else{
            cout<<"I cant find save :( \n";

        }
    }
    save.close();
}

void Csave(int m , int n , int j){
    ofstream save ;
    save.open("saveplayer.txt");

    if(save.is_open()){

//--------------------save anjam shode--------------------------
        save <<1<<endl ;
//------------------ tedad afrad va jadval----------------------
        save <<m<<" "<<n<<endl ;
//---------------------snake and ladders-------------------------
        save<<l<<" " <<sn<<endl;
//-----------------------ladders positions------------------------
        for(int i=1 ; i<=l-1 ; i++){
            save <<px[i]<<" "<<py[i]<<endl;
        }
        save <<z[1]<<" "<<z[10]<<endl;
//-----------------------snakes positions--------------
        for(int i=1 ; i<sn-1 ; i++){
            save <<mx[i]<<" "<<my[i]<<endl;
        }
        save<<z[2]<<" "<<z[20]<<endl;
//-----------------------player positions------------
        save <<j<<endl;
        for(int i=1 ; i<=n ; i++){
            save <<Move[i]<<" ";
        }
        save<<endl;
//-------------------------player info----------------
        for(int i=1 ; i<=n ; i++){
            save<<s[i].name<<" "<<C[i]<<endl;
        }
    }
    save.close();
}

void finish (int p) {
    cout<<s[p].name<<" win the game !";
    cout << endl << "enjoy !!! ;)"<<"\n press 'W' to see what happen To you ... MamadNet ;)"<<endl;
    int i ;
    for( ; ;){
        uniform_real_distribution<double> dic(1.00, 200.90);
        i=(int)dic(gen);
        if(GetKeyState('W')<0 ) {
            color(i);
            cout<<s[p].name << " YOU WIN ";

        }
    }
}

void saving (int i , int j){
    save[i][j]=Move[j];
}

void loading (int n , int u){
    space();
    cout<<"You Are In round "<<u<<"!\n";
    space();
    cout<<"If You Want To Go Back And Play previous Rounds press F2 OR Press 'Enter' \n";
    e=1;
    while(!(GetKeyState(13) & 0x8000)){
        if((GetKeyState(113)& 0x8000)){
            e=0;
            break;
        }
    }
    if(e==0){
        space();
        cout<<" Enter Number of The Round !\n";
        cin>>Round;
        space();
        cout<<" Enter Number Of The player ! \n";
        for(int i=1 ; i<=n ; i++){
            space();
            cout<<"player("<<i<<") : "<<s[i].name<<endl;
        }
        cin>>x;
    }
}

void cmoving(int m , int n , int j , int u , int i ) {
    dice(j , i);
    think(j, m);
    system("cls");
    if (g == 0) {
        g = 50;
        Dmove = 2;
        return;
    }
    if (b != 0) {
        moving(m, n, j);
        emptymap(m, n);
        pointmake(j);
        if (u == 0 and j != n) {
            for (int x = j + 1; x <= n; x++)
                moveorg[x] = x;
        }
        for (int x = 1; x <= n; x++)
            a[row[x]][moveorg[x]] = C[x];
        space();
        cout << "ok you are here now !" << endl;
        map(m, n );
        check(m, n, j, k);
        //debug(m, n);
        win(m, n, j);
        if (g == 0) {
            finish(winer);
            fini = 0;
            return;
        }
        if (g == 1)
            con = 0;
    }
    Csave(m ,n , j);
    if (chance == 6) {
        space();
        if (we == 0) {
            color(14);
            cout << "good for you :) you Have another chance . press any key for using dice " << endl;
        } else {
            color(116);
            cout << "you are so lucky ! press any key for using dice again ;)" << endl;
        }
        getch();

        we++;
        b = 1;
        cmoving(m, n, j, u ,i);
    }
}

void play(int m , int n) {
    system("cls");
    int u = 0;
    for (int i = 1; i <= m * m * m * m; i++) {
        int h = 8 , h1=3;
        for (int k = 1; k <= n; k++) {
            if (k == y[k])
                h = 1;
            else
                h1 = 2;
        }
        if (h == 1 and h1!=2) {
            finish(winer);
        }

        k = 0;
        if (e == 0) {
            i = Round;
            for (int p = 1; p <= n; p++)
                Move[p] = save[i][p];
            k = x - 1;
        }

        space();
        cout << "                  ----> Round " << i << " <----" << endl;
        load();
        cout << endl;
        for (int j = 1; j <= n; j++) {
            color(j + 8);
            saving(i, j);
            if (e == 0) {
                j = x;
                e = 10;
            }
            if (j == y[j]) {
                k++;
                w = 0;
                continue;
            }
            if (e == 0) {

            }
            cmoving(m, n, j, u , i);
            if (Dmove == 2) {
                w = 0;
                k++;
                continue;
            }
            if (fini == 0) {
                return;
            }

            if (con == 0) {
                w = 0;
                k++;
                continue;
            }

            we = 0;
            w = 0;
            k++;

        }
        u++;
        if (i != 1) {
            loading(n, i);
        }
    }
}

int  main() {
    int n, m;
    Hello();
    cout<<endl;
    Cload(m ,n);
    if(checksavee==0) {
        do {
            cout << endl;
            space();
            cout << "How Many People Are You ?(max=8)" << endl;
            cin >> n;
            space();
            cout << "How Many rows and columns do you want ? (better to use 7 and above)" << endl;
            cin >> m;
            waiting();
            space();
            cout << "This is empty map of the game ... :D " << endl << endl;
            calculating(m, n);
            map(m, n);
            cout << "Do you want to change this setting ? press Y Not N " << endl;
            g = 2;
            while (!(GetKeyState('N') & 0x8000)) {
                if ((GetKeyState('Y') & 0x8000)) {
                    g = 1;
                    break;
                }
            }
        } while (g == 1);
        do {
            difficulty(m);
            random(m);
            emptymap(m, n);
            //debug(m , n);
            cout << endl;
            space();
            cout << "this is full map ! " << endl;
            map(m, n);
            space();
            cout << "if you want another map or choose another difficulty  press Y or not press N !" << endl;
            g = 2;
            while (!(GetKeyState('N') & 0x8000)) {
                if ((GetKeyState('Y') & 0x8000)) {
                    g = 1;
                    break;
                }
            }
        } while (g == 1);
        playerinfo(n);
        space();
        cout << "Okay ! this is map and you are in 1-1 :D " << endl;
        map(m, n);
        Sleep(1000);
    }
    space();
    cout << "lets play The game" ;
    cout<<" .";
    Sleep(200);
    cout<<".";
    Sleep(200);
    cout<<".";
    Sleep(200);
    cout<<".\n";
    if(checksavee!=0){
            k=1;
        moving(m , n , n);
        emptymap(m , n );
        map(m , n);
    }
    play(m, n);
}
