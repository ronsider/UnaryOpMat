
#include <array>
#include <cctype>
#include <string>
#include <iostream>
#include <string_view>
#include <span>
#include <algorithm>
#include "../include/EntryPage.hpp"
#include "../include/MatrixPage.hpp"

using std::array;
using std::string;
 
static bool which_page{false};//0 for entry page, 1 for matrix page

int main()
{ 
  
    //set_target_fps();
    InitWindow(900, 700, "Unary Operations On Matrix");//later change to 800X600
    //SetTargetFPS(target_fps);
    SetTargetFPS(20);

    FirstPageProperties::EntryPage PageOne{};
    SecondPageProperties::MatrixPage PageTwo{};
    PageTwo.init_Actions();
    auto& temp = FirstPageProperties::SharedVariables::Dimensions::GetInstance();

    while (!WindowShouldClose())
    {
              
        BeginDrawing();
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
        if (temp.GetBool() == false)
        {    
            PageOne.render_First_Page();
            PageOne.render_input_boxes();
            PageOne.Submit_Button();          
        }
        else
        {
                PageTwo.prt();
                PageTwo.draw_rects();
                PageTwo.render_options();
        }

        EndDrawing();
    }
    
    CloseWindow();
    return 0; 
    
}