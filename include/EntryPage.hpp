#pragma once
#include <iostream>
#include "raylib.h"
#include "raygui.h"

namespace FirstPageProperties
{
    namespace SharedVariables
    {
        class Dimensions// this class serves as singleton to access rows and colomuns and a flag for a page
        {
        public:
            Dimensions(const Dimensions&) = delete;//delete cpy ctr
            Dimensions& operator = (const Dimensions&) = delete;// delete cpy  assign op
            static Dimensions& GetInstance()
            {
                static Dimensions dimensions;
                return dimensions;
            }
            std::size_t GetRows()const
            {
                return m_rows;
            }
            std::size_t GetColumns()const
            {
                return m_columns;
            }
            bool GetBool() const
            {
                return first_page;
            }
            void SetRows(std::size_t rows)
            {
                m_rows = rows;
            }
            void SetColmuns(std::size_t coulmnss)
            {
                m_columns = coulmnss;
            }
            void SetFirstPage(bool value)
            {
                first_page = value;
            }
        private:
            Dimensions() :m_rows{}, m_columns{} {}

            std::size_t m_rows{};
            std::size_t m_columns{};
            bool first_page{};
        };
    };
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

/*Rectangle*/void Submit_Button() const
            {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                {
                auto pos = GetMousePosition();
                 if (CheckCollisionPointRec(pos, submit_box_input))
                    {
                        std::cout << "submit button has been pressed and these are the coordinates : \n" << number_one << "  " << number_two;
                        FirstPageProperties::SharedVariables::Dimensions& dimensions = FirstPageProperties::SharedVariables::Dimensions::GetInstance();
                        dimensions.SetRows(std::stoi(number_one));
                        dimensions.SetColmuns(std::stoi(number_two));
                        dimensions.SetFirstPage(true);
                                            
                    }
            }
             }

    private:
        std::size_t return_col() const
        {
            return m_columns;;
        }
        std::size_t return_row()  const
        {
            return m_rows;
        }


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
        //class data members:
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
        std::size_t m_rows;
        std::size_t m_columns;

    };
};
