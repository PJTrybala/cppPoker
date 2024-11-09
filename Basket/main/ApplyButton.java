public class ApplyButton {
    Command theCommand;

    public ApplyButton(Command command) {
        theCommand = command;
    }

    public void press() {
        theCommand.execute();
    }
}
