class Utils {

    public:
    static int round_floatToInt(float float_num) {
        return (int) (float_num + 0.5 - (float_num<0)); 
    }

};