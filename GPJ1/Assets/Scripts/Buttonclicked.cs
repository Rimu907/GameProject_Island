using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class Buttonclicked : MonoBehaviour
{
    
    // Start is called before the first frame update

   public void ChangeScene(string scenename)
    {
        //Output this to console when Button1 or Button3 is clicked
        SceneManager.LoadScene(scenename);
        Debug.Log("You have clicked the button!");
    }
    public void Quitgame()
    {
        Debug.Log("quit");
        Application.Quit();
    }
}
