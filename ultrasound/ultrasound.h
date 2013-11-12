class Ultrasound
{
  public:
    Ultrasound(int triggerpin, int echopin);
    int measure();
    void dash();
  private:
    int _pin;
};

