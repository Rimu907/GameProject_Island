using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DestroyOnContact : MonoBehaviour
{
    
    
    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {

    }
    private void OnCollisionEnter(Collision collision)
    {
        if (collision.gameObject.tag == "Player")
        {
            collision.gameObject.GetComponent<PlayerHp>().TakeDamage(10);
        }

        if (collision.gameObject.tag == "Enemy")
        {
            collision.gameObject.GetComponent<EnemyHp>().TakeDamage(10);
        }

        if (collision.gameObject.tag == "Boss")
        {
            collision.gameObject.GetComponent<BossHp>().TakeDamage(10);
        }

        DestroyObject(gameObject);
        
    }
}
