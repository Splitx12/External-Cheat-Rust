#include "Main.h"
#include "Vector.h"
#include <vector>

#include "Vallue.h"

class dot
{
public:
    dot(SourceEngine::Vector p, SourceEngine::Vector v) {
        m_vel = v;
        m_pos = p;
    }

    void update();
    void draw();

    SourceEngine::Vector m_pos, m_vel;
};

std::vector<dot*> dots = { };

void dot::update() {
    auto opacity = test1;

    m_pos += m_vel * (opacity);
}

void dot::draw() {

    int opacity = 255.0f * (255.0f / 255.0f);
    if (theme)
        ImGui::GetWindowDrawList()->AddRectFilled({ m_pos.x - 2.5f, m_pos.y - 2.5f }, { m_pos.x + 2.5f, m_pos.y + 2.5f }, ImColor(123, 59, 186), 30);
    else
        ImGui::GetWindowDrawList()->AddRectFilled({ m_pos.x - 2.5f, m_pos.y - 2.5f }, { m_pos.x + 2.5f, m_pos.y + 2.5f }, ImColor(123, 59, 186), 30);
    auto t = std::find(dots.begin(), dots.end(), this);
    if (t == dots.end()) {
        return;
    }

    for (auto i = t; i != dots.end(); i++) {
        if ((*i) == this) continue;

        auto dist = (m_pos - (*i)->m_pos).Length2D();

        if (dist < test) {
            int alpha = opacity * (dist / test);

            if (theme)
                ImGui::GetWindowDrawList()->AddLine({ m_pos.x - 2, m_pos.y - 3 }, { (*i)->m_pos.x - 2, (*i)->m_pos.y - 3 }, ImColor(123, 59, 186));
            else
                ImGui::GetWindowDrawList()->AddLine({ m_pos.x - 2, m_pos.y - 3 }, { (*i)->m_pos.x - 2, (*i)->m_pos.y - 3 }, ImColor(123, 59, 186));
        }
    }
}

void dot_draw() {
    if (particle == true) {
        struct screen_size {
            int x, y;
        }; screen_size sc;

        if (!vector_speed)
            vector_speed = GetTickCount();

        if (GetTickCount() > vector_speed + (1 * 2))
        {
            RECT screen_rect;
            GetWindowRect(GetDesktopWindow(), &screen_rect);

            sc.x = GetSystemMetrics(SM_CXSCREEN / 2);
            sc.y = GetSystemMetrics(SM_CYSCREEN / 2);

            int s = rand() % 16;

            if (s == 0) {
                dots.push_back(new dot(SourceEngine::Vector(rand() % (int)sc.x, -16, 0), SourceEngine::Vector((rand() % 7) - 3, rand() % 3 + 1, 0)));
            }
            else if (s == 1) {
                dots.push_back(new dot(SourceEngine::Vector(rand() % (int)sc.x, (int)sc.y + 16, 0), SourceEngine::Vector((rand() % 7) - 3, -1 * (rand() % 3 + 1), 0)));
            }
            else if (s == 2) {
                dots.push_back(new dot(SourceEngine::Vector(-16, rand() % (int)sc.y, 0), SourceEngine::Vector(rand() % 3 + 1, (rand() % 7) - 3, 0)));
            }
            else if (s == 3) {
                dots.push_back(new dot(SourceEngine::Vector((int)sc.x + 16, rand() % (int)sc.y, 0), SourceEngine::Vector(-1 * (rand() % 3 + 1), (rand() % 7) - 3, 0)));
            }

            auto alph = 255.0f * (255.0f / 255.0f);
            auto a_int = (int)(alph);

            ImGui::GetWindowDrawList()->AddRectFilled({ 0, 0 }, { (float)sc.x, (float)sc.y }, ImColor(a_int, 0, 0, 0));

            for (auto i = dots.begin(); i < dots.end();) {
                if ((*i)->m_pos.y <= -20 || (*i)->m_pos.y > sc.y + 20 || (*i)->m_pos.x < -20 || (*i)->m_pos.x > sc.x + 20) {
                    delete (*i);
                    i = dots.erase(i);
                }
                else {
                    (*i)->update();
                    i++;
                }
            }
            vector_speed = 0;
        }
        for (auto i = dots.begin(); i < dots.end(); i++) {
            (*i)->draw();
        }
    }
}

void dot_destroy() {
    for (auto i = dots.begin(); i < dots.end(); i++) {
        delete (*i);
    }

    dots.clear();
}
