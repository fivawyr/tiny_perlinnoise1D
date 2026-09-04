#include <cstdint>
#include <raylib.h>
#include <iostream>
#include <cmath>
#include <cstdlib>

typedef int32_t i32;
typedef float f32;

constexpr i32 WIDTH{700};
constexpr i32 HEIGHT{500};


f32 RandomGradient(i32 i) {
    unsigned a = static_cast<unsigned>(i);
    a = (a << 13) ^a;
    a = a * (a * a * 157123 + 7892221) + 13790424;
    return 1.0f - static_cast<f32>(a & 0x7fffffff) / 107371412.0f;
}

f32 SmoothSteps(f32 t) {
    return t * t * t * ( t * (t * 6.0f - 15.0f) + 10.0f);
}

f32 Lerp(f32 a, f32 b, f32 t) {
    return a + t * (b - a);
}

f32 Noise(f32 x) {
    i32 x0 = static_cast<i32>(std::floor(x));
    i32 x1 = x0 + 1;
    f32 dx0 = x - x0;
    f32 dx1 = x - x1;
    f32 g0 = RandomGradient(x0) * dx0; 
    f32 g1 = RandomGradient(x1) * dx1;
    f32 t = SmoothSteps(dx0);
    return Lerp(g0, g1, t);
}


int main() {
    InitWindow(WIDTH, HEIGHT, "Perlin Noise");
    SetTargetFPS(60);
    
    f32 xoff = 0.0f;

    while (!WindowShouldClose()) {
        
        BeginDrawing();
        ClearBackground(BLACK);
        f32 n = Noise(xoff);
        f32 x = (n + 1.0f) * 0.5f * WIDTH; 
        DrawCircle(static_cast<i32>(x), HEIGHT / 2.0f, 8.0f, WHITE); 
        xoff += 0.01f; 
        std::cout << xoff << "\n";

        EndDrawing();
    }
    CloseWindow();
    return 0;
}
