#pragma once
#include "EntryPage.hpp"

namespace SecondPageProperties
{
    struct MatrixPage
    {
        struct Options
        {
            std::string option;
            Rectangle Button{};
        };

        std::array<Options, 8>Actions_Layout;
    
        void prt() const
        {
            auto& temp = FirstPageProperties::SharedVariables::Dimensions::GetInstance();
            std::cout << temp.GetRows() << '\n';
            std::cout << temp.GetColumns() << '\n';
        }
        void init_Actions()
        {
            Actions_Layout[0] = { "Transposition",{ 0,0,78,40} };
            Actions_Layout[1] = { "Determinant",{ 0,60,78,40} };
            Actions_Layout[2] = { "Inversion",{0,125,78,40} };
            Actions_Layout[3] = { "Trace",{0,185,78,40} };
            Actions_Layout[4] = { "Norm",{0,245,78,40} };
            Actions_Layout[5] = { "Multiplication",{0,305,78,40} };
            Actions_Layout[6] = { "Power",{0,365,78,40} };
            Actions_Layout[7] = { "Rank",{0,425,78,40} };
        }

        void draw_rects()
        {
            /*SetDim(dims.GetRows(), dims.GetColumns());
            auto& [r, c] = get_dims();*/
            int count = 0;
            //old function parametrs area width = 100
            //and change all instances of 40 to 50
            float width{ 78 };
            float height{};

            //while (width <= 800 /* && height <= 600*/)
            //{

            //    while (height <= 600)
            //    {
            //        GuiButton({ width,height,40,40 }, std::to_string(count).c_str());
            //        height += 40;
            //        //std::cout<<count++;
            //        count++;
            //    }

            //    height = 0;
            //    width += 40;
            //}


          /*  for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    GuiButton({ width,height,40,40 }, std::to_string(count).c_str());
                    height += 40;
                    count++;
                }
            }
            */
            count = 0;
        }

        void render_options() const
        {
            for (const auto& i : Actions_Layout)
            {
                GuiButton(i.Button, i.option.c_str());


            }
            GuiDrawIcon(118, 20, 470, 3, GRAY);
        }
        
    private:
        //FirstPageProperties::SharedVariables::Dimensions& dims = FirstPageProperties::SharedVariables::Dimensions::GetInstance();
        std::size_t m_rows;
        std::size_t m_columuns;

        auto get_dims() -> std::pair<std::size_t, std::size_t> const
        {
            return { m_rows, m_columuns };
        }

        void SetDim(std::size_t rows, std::size_t columns)
        {
            m_rows = rows;
            m_columuns = columns;
        }
    };

};
