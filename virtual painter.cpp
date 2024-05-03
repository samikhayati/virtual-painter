#include <iostream>
#include <windows.h>
#include<stdio.h>
#include <math.h>
#include <ctime>
#include <cstdio>
#include <map>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#pragma comment(lib, "Gdi32.lib")

//before usage here is how it works
//this bot draws the colors


using namespace std;
using namespace cv;


int movecursorfast(int ix, int iy, POINT PV, int Psize) {
    while (true) {
        if (ix < PV.x) {
            ix = ix + Psize;
        }
        if (PV.x < ix) {
            ix = ix - Psize;
        }
        if (iy < PV.y) {
            iy = iy + Psize;
        }
        if (PV.y < iy) {
            iy = iy - Psize;
        }
        SetCursorPos(ix, iy);
        Sleep(1);
        if ((max(PV.x - ix, ix - PV.x) < Psize) && (max(PV.y - iy, iy - PV.y) < Psize)) {
            SetCursorPos(PV.x, PV.y);
            return 0;
        }

        if ((ix == PV.x) && (iy == PV.y)) { return 0; }

        if (GetAsyncKeyState(VK_NUMPAD0)) {
            return 0;
        }
    }


}

void cursorwhencolorchanges(int ix, int iy, int Psize) {
    while (iy >= 300) {
        iy = iy - Psize;
        SetCursorPos(ix, iy);
        Sleep(1);
    }
}


int main()
{             //22 before modification (works fine)
    int ccord[49][3] = { {105,221,0},{225,204,0},{255,126,0}, {255,61,61},{192,0,255},{255,62,212}, {0,120,255},{0,222,255},{255,255,255},{0,0,0}
        ,{242,238,135},{133,0,0},{40,112,40},{144,238,144},{16,32,136},{173,216,230},{128,0,128},{255,182,193},{255,216,177},{255,250,200},
        {170,255,195},{70,153,144},{102,0,0},{153,0,0},{204,0,0},{255,0,0},{255,153,51},{255,128,0},{204,102,0},{255,178,102},{255,255,0}
        ,{255,255,51},{255,255,102},{255,255,153},{102,204,0},{0,204,0},{0,102,0},{51,255,51},{102,255,255},{0,255,255},{0,153,153},{153,255,255}
        ,{0,0,255},{0,128,255},{51,153,255},{0,0,153},{211, 97, 53},{218,165,32},{128,128,0}





    };
    string cname[49] = { "green","yellow","orange","red","purple","rose","blue","lightblue","white","black","yellow","red","green","green","blue","lightblue","purple","rose","orange",
        "yellow","green","blue","red","red","red","red","orange","orange","orange","orange","yellow","yellow","yellow","yellow","green","green",
        "green","green","lightblue","lightblue","lightblue","lightblue","blue","blue","blue","blue","orange","yellow","green"


    };
    map<string, map<int, int>> CD = { {"green",{{0,105},{1,221},{2,0}}}, //a dictionary contains  keys:(strings)color names , values:dictionaries in the style of an array 0 contains red color value 
            {"yellow",{{0,255},{1,204},{2,0}}},{"orange",{{0,255},{1,126},{2,0}}},{"red",{{0,255},{1,61},{2,61}}}, // 1 contains green color nd 2 for blue
            {"purple",{{0,192},{1,0},{2,255}}},{"rose",{{0,255},{1,62},{2,212}}},{"blue",{{0,0},{1,120},{2,255}}},
            {"lightblue",{{0,0},{1,222},{2,255}}},{"white",{{0,255},{1,255},{2,255}}},
            {"black",{{0,42},{1,42},{2,42}}} };
    string path = "Agario_wolf.webp";
    Mat img = imread(path);
    rotate(img, img, ROTATE_90_CLOCKWISE); //rotating the image becasue of a problem in my code (will paint images rotated in the wrong direction)
    imshow("nonmod", img);
    Vec3b black = { 0,0,0 };
    int x = 500, XD, XM;               //so basically this program puts a chess board theme on any image but it will help me in the auto painetr project
    XD = (img.rows) / x; //div        //x is the number of lines and y is the number of colloms
    XM = (img.rows) % x; //mod        //currently i tested it on 2 pictures and it works (102,102)
    int y = 500, YD, YM;
    YD = (img.cols) / y; //div
    YM = (img.cols) % y; //mod
    int b = 1, a = 0, e = 0, d = 1;
    int B = 0, G = 0, R = 0, S = 0;






    int X, A, C;
    X = 999;
    A = 0;                                              //NOTE:THIS PROGRAM DOSNT WORK WITH BROWN COLOR OR ANYTHING SIMILAR
    C = 10;                                             //not because it cant do that but becasue the game that i m going to use this program on  dosnt have brown color
    POINT CP;

    vector<POINT> Vgreen; vector<POINT> Vyellow; vector<POINT> Vorange; vector<POINT> Vred; vector<POINT> Vpurple; vector<POINT> Vrose;
    vector<POINT> Vblue; vector<POINT> Vlightblue; vector<POINT> Vwhite; vector<POINT> Vblack;
    map<string, vector<POINT>> VDICT{ {"green",Vgreen},{"yellow",Vyellow} ,{"orange",Vorange} ,{"red",Vred} ,{"purple",Vpurple},
    {"rose",Vrose},{"blue",Vblue} ,{"lightblue",Vlightblue} ,{"white",Vwhite} ,{"black",Vblack} }; // a dictionary contains  keys :color name
    //valuez:vectors that contain coclor positions in agario paint screen
    map<string, POINT> DCOLOAGAR;  //dictionary with agario color positions
    CP.x = 528; CP.y = 362; DCOLOAGAR["green"] = CP; CP.x = 594; CP.y = 362; DCOLOAGAR["yellow"] = CP; CP.x = 528; CP.y = 436; DCOLOAGAR["orange"] = CP;
    CP.x = 594; CP.y = 436; DCOLOAGAR["red"] = CP; CP.x = 594; CP.y = 510; DCOLOAGAR["rose"] = CP; CP.x = 528; CP.y = 510; DCOLOAGAR["purple"] = CP;
    CP.x = 528; CP.y = 588; DCOLOAGAR["blue"] = CP; CP.x = 594; CP.y = 588; DCOLOAGAR["lightblue"] = CP;
    CP.x = 528; CP.y = 661; DCOLOAGAR["white"] = CP; CP.x = 594; CP.y = 661; DCOLOAGAR["black"] = CP;
    map<string, POINT> DCOLOMSPAINT;  //dictionary with mspaint color positions
    CP.x = 1012; CP.y = 60; DCOLOMSPAINT["green"] = CP; CP.x = 989; CP.y = 60; DCOLOMSPAINT["yellow"] = CP; CP.x = 967; CP.y = 60; DCOLOMSPAINT["orange"] = CP;
    CP.x = 946; CP.y = 61; DCOLOMSPAINT["red"] = CP; CP.x = 946; CP.y = 83; DCOLOMSPAINT["rose"] = CP; CP.x = 1076; CP.y = 61; DCOLOMSPAINT["purple"] = CP;
    CP.x = 1056; CP.y = 61; DCOLOMSPAINT["blue"] = CP; CP.x = 1033; CP.y = 60; DCOLOMSPAINT["lightblue"] = CP;
    CP.x = 882; CP.y = 81; DCOLOMSPAINT["white"] = CP; CP.x = 881; CP.y = 58; DCOLOMSPAINT["black"] = CP;
    map<string, POINT> DCOLOSKRIBBL;  //dictionary with skribbl.io color positions
    CP.x = 536; CP.y = 812; DCOLOSKRIBBL["green"] = CP; CP.x = 512; CP.y = 815; DCOLOSKRIBBL["yellow"] = CP; CP.x = 486; CP.y = 813; DCOLOSKRIBBL["orange"] = CP;
    CP.x = 466; CP.y = 811; DCOLOSKRIBBL["red"] = CP; CP.x = 631; CP.y = 810; DCOLOSKRIBBL["rose"] = CP; CP.x = 610; CP.y = 839; DCOLOSKRIBBL["purple"] = CP;
    CP.x = 585; CP.y = 814; DCOLOSKRIBBL["blue"] = CP; CP.x = 561; CP.y = 813; DCOLOSKRIBBL["lightblue"] = CP;
    CP.x = 416; CP.y = 810; DCOLOSKRIBBL["white"] = CP; CP.x = 416; CP.y = 835; DCOLOSKRIBBL["black"] = CP;
    int Psize = 1;
    int IXagar = 702;
    int Xagario = 702, Yagario = 776;
    POINT Pagario;
    map<string, int> TempColorFinder;
    int MaxCV;
    String Cstring;
    vector<String> Cvector;
    vector<POINT> Pvector;
    for (int ii = 0; ii < y; ii++) {             //buffers for every color that contains color positions in agario painting screen
        if (XM == 0) { b = 0; }            //initilazing b if XM=0 because if i dont i could be in situations were (img.rows<(i+1)*XD+b) wich results in a error
        if (YM == 0) { d = 0; }
        for (int i = 0; i < x; i++) {
            for (int r = i * XD + a; r < (i + 1) * XD + b; r++) {
                for (int c = ii * YD + e; c < (ii + 1) * YD + d; c++) {
                    B = img.at<Vec3b>(r, c)[0];
                    G = img.at<Vec3b>(r, c)[1];
                    R = img.at<Vec3b>(r, c)[2];
                    TempColorFinder.clear();
                    X = 999;
                    //S = S + 1;
                    for (int iii = 0; iii < 49; iii++) {


                        A = abs(ccord[iii][0] - R) + abs(ccord[iii][1] - G) + abs(ccord[iii][2] - B);
                        if (A < X) {
                            X = A;
                            C = iii;



                        }

                    }
                    if (((R == G) && (G == B)) && (R < 120)) {
                        C = 9;
                    }
                    if (((R == G) && (G == B)) && (R > 120)) {
                        C = 8;
                    }
                    TempColorFinder[cname[C]] = TempColorFinder[cname[C]] + 1;

                }
            }
            MaxCV = 1;
            for (auto [Key, Value] : TempColorFinder) {
                if (Value >= MaxCV) {
                    MaxCV = Value;
                    Cstring = Key;
                }
            }
            /*
            B = B / S;
            G = G / S;
            R = R / S;
            */
            /*
            S = 0;
            X = 999;
            for (int iii = 0; iii < 49; iii++) {


                A = abs(ccord[iii][0] - R) + abs(ccord[iii][1] - G) + abs(ccord[iii][2] - B);
                if (A < X) {
                    X = A;
                    C = iii;



                }

            }
            if (((R == G) && (G == B)) && (R < 120)) {
                C = 9;
            }
            if (((R == G) && (G == B)) && (R > 120)) {
                C = 8;
            }
            */
            Pagario.x = Xagario;
            Pagario.y = Yagario;
            Cvector.push_back(Cstring);
            Pvector.push_back(Pagario);
            Xagario = Xagario + Psize;
            R = CD[Cstring][0];
            G = CD[Cstring][1];
            B = CD[Cstring][2];

            for (int r = i * XD + a; r < (i + 1) * XD + b; r++) {
                for (int c = ii * YD + e; c < (ii + 1) * YD + d; c++) {
                    img.at<Vec3b>(r, c)[0] = B;
                    img.at<Vec3b>(r, c)[1] = G;
                    img.at<Vec3b>(r, c)[2] = R;
                }
            }
            B = G = R = 0;
            if (b < XM) { b = b + 1; }
            if (a < XM) { a = a + 1; }
        }
        b = 1;
        a = 0;
        if (e < YM) { e = e + 1; }
        if (d < YM) { d = d + 1; }
        Yagario = Yagario - Psize;
        Xagario = IXagar;


    }
    imshow("mod", img);
    //waitKey(0);



    POINT OVX;
    String tempcolor = "";
    bool mousedown = false;
    int mousecount = 0;
    INPUT input = { 0 };
    //cout << img.rows << "x" << img.cols;
    while (1) {
        if (GetAsyncKeyState(VK_NUMPAD5)) {
            for (int i = 1; i < Cvector.size(); i++) {
                if (i == 1) {
                    SetCursorPos(Pvector[i - 1].x, Pvector[i - 1].y);
                }

                if (Cvector[i] != tempcolor) {
                    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
                    SendInput(1, &input, sizeof(input));
                    mousecount = 0;
                    mousedown = false;
                    Sleep(1);
                    OVX.x = DCOLOAGAR[Cvector[i]].x;
                    OVX.y = DCOLOAGAR[Cvector[i]].y;
                    movecursorfast(Pvector[i - 1].x, Pvector[i - 1].y, OVX, 100);
                    input = { 0 };
                    input.type = INPUT_MOUSE;
                    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
                    SendInput(1, &input, sizeof(input));
                    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
                    SendInput(1, &input, sizeof(input));
                    tempcolor = Cvector[i];
                    OVX.x = Pvector[i].x + 50;
                    OVX.y = Pvector[i].y - 50;
                    movecursorfast(DCOLOAGAR[Cvector[i]].x, DCOLOAGAR[Cvector[i]].y, OVX, 100);
                    Sleep(1);

                }
                else {
                    if (Pvector[i].y != Pvector[i - 1].y) {
                        input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
                        SendInput(1, &input, sizeof(input));
                        mousedown = false;
                        Sleep(1);
                        OVX.x = Pvector[i].x + 50;
                        OVX.y = Pvector[i].y - 50;
                        movecursorfast(Pvector[i - 1].x, Pvector[i - 1].y, OVX, 100);

                    }
                }
                SetCursorPos(Pvector[i].x, Pvector[i].y);
                if (mousedown == false) {
                    Sleep(1);
                    input = { 0 };
                    input.type = INPUT_MOUSE;
                    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
                    SendInput(1, &input, sizeof(input));
                    mousedown = true;

                }
                else {
                    if ((mousecount % 50 == 0) && (mousecount != 0)) {
                        mousecount = mousecount + 1;
                        Sleep(1);
                        input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
                        SendInput(1, &input, sizeof(input));
                        input = { 0 };
                        input.type = INPUT_MOUSE;
                        input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
                        SendInput(1, &input, sizeof(input));


                    }
                    else if (mousecount <= 10) {
                        Sleep(1);
                        mousecount = mousecount + 1;
                    }

                    else {
                        mousecount = mousecount + 1;

                        for (int j = i + 1; j < i + 11; j++) {
                            if (Cvector[j] != tempcolor) {
                                Sleep(1);
                                break;
                            }
                        }
                    }





                }


                if (GetAsyncKeyState(VK_NUMPAD7)) {
                    Sleep(50000);
                }

            }


        }
        if (GetAsyncKeyState(VK_NUMPAD0)) {
            return 0;
        }



    }


    return 0;

    Sleep(500);
    //if the code isnt working just check this video
    //https://www.youtube.com/watch?v=2FYm3GOonhk&ab_channel=Murtaza%27sWorkshop-RoboticsandAI



}