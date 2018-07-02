
package mk;
import org.openqa.selenium.chrome.ChromeDriver;
import utility.ExcelUtil;
import utility.constant;
/**
 *
 * @author SATYAM
 */
public class Mk{
    
    public static void main(String[] args) {
        
      String exePath = "C:\\Users\\SATYAM\\Downloads\\Compressed\\chromedriver_win32\\chromedriver.exe";
      System.setProperty("webdriver.chrome.driver", exePath);
      homePage obj = new homePage(new ChromeDriver());
      obj.gotosite();
      obj.logintomk();
    
         
       
    }
    
}
