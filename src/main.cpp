#include "raylib.h"
#include "raygui.h"
#include <array>
#include <cctype>
#include <string>
#include <iostream>
#include <string_view>
#include <span>
#include <algorithm>
using std::array;
using std::cout;
using std::string;

struct EntryPage
{
    
public:
    EntryPage()
    {
        _result = LoadFont("resources/OpenSans-Regular.ttf");
        Header = LoadTexture("resources/page_one_header.png");
    }
    EntryPage(const EntryPage&) = delete;
    EntryPage& operator=(EntryPage&) = delete;
    ~EntryPage()
    {
        UnloadFont(_result);
        UnloadTexture(Header);
    }


    void render_First_Page() const
    {
        DrawTexture(Header, 0, 0, WHITE);
        DrawTextEx(_result, instructions, { 60,60 }, 30, 2.0, DARKBROWN);
        DrawTextEx(_result, "ROWS", { 200, 380 }, 20.0f, 2.0f, BLACK);
        DrawTextEx(_result, "COLUMNS", { 300, 380 }, 20.0f, 2.0f, BLACK);
        GuiDummyRec(submit_box_input, "SUBMIT");

        
    }
    void render_input_boxes()
    {
        guiBoxFunction(number_one, Rows_Box, edit_mode_one);
        guiBoxFunction(number_two, Columns_Box, edit_mode_two);
    }

    /*Rectangle*/ void Which_box() const
        {
       if( IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
           auto pos = GetMousePosition();
           if (CheckCollisionPointRec(pos, submit_box_input))
           {
               cout << "submit button has been pressed\n";
           }
        }
        }



private:
    //functions:
    int guiBoxFunction(char* number, const Rectangle& Button, bool& edit_mode)
    {
        auto number_size = [&number](std::string_view string_number)
            {
                auto temp_result = std::atoi(string_number.data());
                if (string_number.size() > 2 || temp_result > 20)
                {
                    return false;
                }
                return true;
            };
        if (number_size(number) == false) // number is in the range of 1-20
        {
            number[0] = '2';
            number[1] = '0';
            number[2] = '\0';
            number[3] = '\0';
        }
        const int text_size = 64;
        int result{};
        //if (result = GuiTextBox(Button, const_cast<char*>(number.data()), text_size, edit_mode); result)
        if (result = GuiTextBox(Button, number, text_size, edit_mode); result)
        {
            edit_mode = !edit_mode;
        }
        return result;
    }
    const char* instructions = "- Matrix Transposition\n\n\
- Matrix Determinant\n\n\
- Matrix Inversion\n\n\
- Matrix Trace\n\n\
- Matrix Norm\n\n\
- Scalar Multiplication\n\n\
- Matrix Power\n\n\
- Matrix Rank";

    const Rectangle Rows_Box = { 200,400, 60, 50 };
    const Rectangle Columns_Box = { 300, 400, 60, 50 };
    Rectangle submit_box_input{ 440,400,50,50 };

    Font _result;
    Texture2D Header;
    bool edit_mode_one = false;
    bool edit_mode_two = false;
    char number_one[4] = { "1" };//rows
    char number_two[4] = { "1" };//columns
    //number_one[2] = '\0';
    //number_two[2] = '\0';


};

struct MatrixPage
{
    struct Options
    {
        std::string option;
        Rectangle Button{};
    };

    void ZoomInOverCell(const Options& cell)
    {
       // DrawRectangleRec(cell.Button, WHITE);
        //DrawRectangleLines(cell.Button, BLACK);
        DrawRectangleLinesEx(cell.Button, 0.7, BLACK);
        DrawText(cell.option.c_str(), cell.Button.x+cell.Button.x/4, cell.Button.y+cell.Button.y / 2, 10, BLACK);
    }

    //zoom in on the result of cell
    void hover_over_cell(const Rectangle& cell)
    {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            auto mouse_position = GetMousePosition();
            auto x = mouse_position.x / 10;
            auto y = mouse_position.y / 10;

        }
    }
    Options opt_test{ "9hello", {70,70,70,70} };
    std::array<Options, 8>Actions_Layout;
    std::size_t m_rows;
    std::size_t m_columuns;
    

    void init_Actions()
    {
        Actions_Layout[0] = { "Transposition",{ 10,0,90,40} };
        Actions_Layout[1] = { "Determinant",{ 10,60,90,40} };
        Actions_Layout[2] = { "Inversion",{10,125,90,40} };
        Actions_Layout[3] = { "Trace",{10,185,90,40} };
        Actions_Layout[4] = { "Norm",{10,245,90,40} };
        Actions_Layout[5] = { "Multiplication",{10,305,90,40} };
        Actions_Layout[6] = { "Power",{10,365,90,40} };
        Actions_Layout[7] = { "Rank",{10,425,90,40} };
    }

    void render_options() const
    {
        for (const auto& i : Actions_Layout)
        {
            GuiButton(i.Button, i.option.c_str());
        }
        GuiDrawIcon(118, 20, 470, 3, GRAY); 
    }
};



static int target_fps;
static bool condition = 0;//which page are we on. entry page=0, matrix page is 1

static void set_target_fps()
{
    target_fps = (condition) ? 15 : 30;//15 fps for entry and 30 for matrix page
}




int main()
{ 
    set_target_fps();
    InitWindow(800, 600, "Unary Operations On Matrix");
    SetTargetFPS(target_fps);

    EntryPage PageOne{};
    MatrixPage PageTwo{};

    PageTwo.init_Actions();
    

    while (!WindowShouldClose())
    {

        //PageOne.Which_box();
        // Draw
        //----------------------------------------------------------------------------------    
       
        BeginDrawing();
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

       // PageOne.render_First_Page();
        //PageOne.render_input_boxes();
        PageTwo.render_options();

        
        GuiButton({ 150,300,50,50 }, "123");
        GuiButton({ 200,300,50,50 }, "456");
        GuiButton({ 250,300,50,50 }, "789");


        GuiButton({ 300,300,50,50 }, "123");
        GuiButton({ 350,300,50,50 }, "456");
        GuiButton({ 400,300,50,50 }, "789");
        GuiButton({ 450,300,50,50 }, "111");
        GuiButton({ 500,300,50,50 }, "222");

        GuiButton({ 550,300,50,50 }, "000");
        GuiButton({ 600,300,50,50 }, "111");
        GuiButton({ 650,300,50,50 }, "222");
        GuiButton({ 700,300,50,50 }, "333");
        GuiButton({ 750,300,50,50 }, "444");

        PageTwo.ZoomInOverCell(PageTwo.opt_test);

        
        EndDrawing();
    }
    CloseWindow();
    return 0;

}