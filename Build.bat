@echo Building GLFW Application...
for /r %%i in (*.cpp) do (
    g++ -c -I. %%i
)

@echo Compilation complete, proceeding to linking...
g++ -o app.exe *.o -L. -lglfw3 -lopengl32 -lgdi32 -lglew32
@echo Linking complete, running application...
.\app
