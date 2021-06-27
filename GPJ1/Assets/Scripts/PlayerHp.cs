using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class PlayerHp : MonoBehaviour
{

    private int MaxHP = 100;
    private int MaxSD = 100;

    public Slider hpslider;
    public Slider sdslider;

    public int CurrentHP;
    public int CurrentSD;

    private ScreenFlash sf;
    public Inventory inventory;
    public GameObject potion;
    public GameObject shield;



    // Start is called before the first frame update

    private void Start()
    {
        CurrentHP = MaxHP;
        CurrentSD = (int)(0.25f * MaxSD);
        ShowSDSlider();
        sf = GetComponent<ScreenFlash>();

    }
    void Update()
    {
 
    }

    public void TakeDamage(int damage)
    {
        sf.FlashScreen();
        CurrentSD -= 25;
        ShowSDSlider();
        if (CurrentSD == -25)
        {
            CurrentSD = 0;
            
            CurrentHP -= damage;
            ShowHPSlider();
            if (CurrentHP <= 0)
            {
                CurrentHP = 0;
                SceneManager.LoadScene("Dead");
            }
        }


        //CurrentHP -= damage;
        //ShowHPSlider();
        //if (CurrentHP <= 0)
        //{
        //    CurrentHP = 0;
        //    SceneManager.LoadScene("Dead");

        //    //CurrentHP = 100;
        //}
    }
    
    //void Inventory_ItemUsed(object sender, InventoryEventArgs e)
    //{
    //    // check if the correct item is in use
    //    if ((e.item as MonoBehaviour).gameObject == potion)
    //    {
    //        Debug.Log("is healing");
    //        gameObject.GetComponent<PlayerHp>().Heal();
    //        inventory.removeItem(potion.GetComponent<IInventoryItem>());
    //    }

    //}

    public void Heal()
    {
        Sound.Playpotion();
        CurrentHP += 10;
        ShowHPSlider();
        if (CurrentHP == 100)
        {
            CurrentHP = 100;
        }
    }
    public void Charge()
    {
        Sound.Playpotion();
        CurrentSD += 25;
        ShowSDSlider();
        if (CurrentSD == 100)
        {
            CurrentSD = 100;
        }
    }



    public void ShowHPSlider()
    {
        hpslider.value = (float)CurrentHP / (float)MaxHP;
    }
    
    public void ShowSDSlider()
    {
        sdslider.value = (float)CurrentSD / (float)MaxSD;
    }


}
