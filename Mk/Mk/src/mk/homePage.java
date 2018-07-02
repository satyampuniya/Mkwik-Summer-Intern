
package mk;

import java.awt.print.Book;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import jxl.Cell;
import jxl.Sheet;
import jxl.Workbook;
import jxl.read.biff.BiffException;
import org.openqa.selenium.chrome.ChromeDriver;
import utility.constant;
import utility.ExcelUtil;




public class homePage { 
static WebDriver driver;
By username = By.name("userid");
By pass = By.name("password");
By loginbtn = By.xpath("//*[@id=\"loginForm\"]/div/div[3]/input");
String str1,str2;

public homePage(WebDriver driver)
    {
        this.driver = driver;
    }
    
public void gotosite(){
    driver.get("https://hstgadmin2.mobikwik.com//");
}
public void setusername(String str1)
    {
        driver.findElement(username).sendKeys(str1);
    }

public void setpassword(String str2)
    {
        driver.findElement(pass).sendKeys(str2);
    }

public void clicklogin()
    {
        driver.findElement(loginbtn).click();
    }

public void logintomk()
    {
    try {
        execute(driver);
    } catch (Exception ex) {
        Logger.getLogger(homePage.class.getName()).log(Level.SEVERE, null, ex);
    }
        this.setusername(str1);
        this.setpassword(str2);
        this.clicklogin();
    }

public static void execute(WebDriver driver) throws Exception{
 
			//This is to get the values from Excel sheet, passing parameters (Row num &amp; Col num)to getCellData method
 
			String str1= ExcelUtil.getCellData(1, 1);
 
			String str2 = ExcelUtil.getCellData(1, 2);
 
/*homePage.setusername(str1);
 
			homePage.settxtbx_Password(driver).sendKeys(sPassword);
 
			homePage.btn_LogIn(driver).click();
 */
        }
 

public static void main(String args[])
{
    
      String exePath = "C:\\Users\\SATYAM\\Downloads\\Compressed\\chromedriver_win32\\chromedriver.exe";
      System.setProperty("webdriver.chrome.driver", exePath);
      homePage obj = new homePage(new ChromeDriver());
      obj.gotosite();
      obj.logintomk();
    
     
}
}
