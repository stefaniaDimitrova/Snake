#pragma once

class Control
{
    private:
    char up, down, left, right;

    public:
    Control(char up, char down, char left, char right);

    const char getUp() const;
    const char getDown() const;
    const char getLeft() const;
    const char getRight() const;

    virtual ~Control() = default;
};