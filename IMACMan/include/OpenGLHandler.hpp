
#ifndef IMACGL_OPENGLHANDLER_HPP
#define IMACGL_OPENGLHANDLER_HPP


class OpenGLHandler {
public:
    int start(const std::string &dirPath);
    static OpenGLHandler& getInstance()
    {
        static OpenGLHandler instance;
        return instance;
    }

    ~OpenGLHandler();
private:
    OpenGLHandler();

};


#endif //IMACGL_OPENGLHANDLER_HPP
