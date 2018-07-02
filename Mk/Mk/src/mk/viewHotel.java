
package mk;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;

public class viewHotel{
        
    WebDriver driver;
    
    By view = By.xpath("\"/html/body/div/section/div/div/div[1]/div/div[2]/div/a[2]\"");
    By down = By.xpath("\"//*/i[@class='caret fR']\"");
    By cityname = By.xpath("//*/a/div[text()='City']");
    By searchH = By.xpath("//*/div/input[@name='searchValue']");
    By btnSearch = By.xpath("//*/button[text()='Search']");
    By selectH = By.xpath("//*/a/strong[text()='Airport Hotel T3 Classic']");
    By editH = By.xpath("//*/div/a[@class = 'mar20 mright csrPtr']");
    
    public viewHotel(WebDriver driver){
        this.driver = driver; 
    }
    
    public void viewclk(){
        driver.findElement(view).click();
    }
    
    public void down(){
        driver.findElement(down).click();
    }
    
    public void selection(){
        driver.findElement(cityname).click();
    }
    
    public void searches(){
        driver.findElement(searchH).sendKeys("Delhi");
    }
    
    public void searchclk(){
        driver.findElement(btnSearch).click();
    }
    
    public void selecths(){
        driver.findElement(selectH).click();
    }
    
    public void edithotel(){
        driver.findElement(editH).click();
    }
 public void workView(){
     this.viewclk();
     this.down();
     this.selection();
     this.searches();
     this.searchclk();
     this.selecths();
 this.edithotel();
    }
 
}
