public class BeijinTime {
    private int hour;
    private int minute;
    private int second;

    public BeijinTime(int hour,int minute,int second) {
        this.hour = hour;
        this.minute = minute;
        this.second = second;
    }

    public void println() {
        System.out.println(hour + ":"+ minute + ":" + second);
    }

    public void setHour(int hour) {
        this.hour = hour;
    }

    public int getHour() {
        return hour;
    }

    public void setMinute(int minute) {
        this.minute = minute;
    }

    public int getMinute() {
        return minute;
    }

    public void setSecond(int second) {
        this.second = second;
    }

    public int getSecond() {
        return second;
    }
}

