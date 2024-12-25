package chapter2;

public class Telephone{
      String number;

      //Construction
      public Telephone() {
            ;
      }
      public Telephone(String number) {
            this.setNumber(number);
      }

      //set
      public void setNumber(String number) {
            if(number.length() == 11) {
                  this.number = number;
            } else {
                  System.out.printf("Error:In the Telephone->setNumber:%n");
                  System.out.printf("Length of number is error%n");
            }
      }

      //get
      public String getNumber() {
            return this.number;
      }

      public String F0() {
           String re = "";

          re += this.getNumber().substring(0,3);
          re += "****";
          re += this.getNumber().substring(7,11);

          return re;
      }
}
