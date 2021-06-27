using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GravityGun : MonoBehaviour
{
    GameObject heldObject = null;
    public Transform holdPosition;
    public LayerMask layerMask;
    bool fire = false;

    // Update is called once per frame
    void Update()
    {
        if (Input.GetKeyDown("e"))
        {
            if (heldObject == null)
            {
                RaycastHit colliderHit;

                if (Physics.Raycast(transform.position, transform.forward, out colliderHit, 10.0f, layerMask))
                {
                    heldObject = colliderHit.collider.gameObject;
                    heldObject.GetComponent<Rigidbody>().useGravity = false;
                }
            }
        }

        if (Input.GetKeyUp("e"))
        {
            if (heldObject != null)
            {
                heldObject.GetComponent<Rigidbody>().useGravity = true;

                heldObject.GetComponent<Rigidbody>().velocity = Vector3.zero;
                heldObject.GetComponent<Rigidbody>().angularVelocity = Vector3.zero;
                heldObject.GetComponent<Rigidbody>().ResetInertiaTensor();

                heldObject = null;
            }
        }

        if (Input.GetButtonDown("Fire2"))
        {
            fire = true;   
        }
    }

    private void FixedUpdate()
    {
        if (heldObject != null)
        {
            heldObject.GetComponent<Rigidbody>().MovePosition(holdPosition.position);
            heldObject.GetComponent<Rigidbody>().MoveRotation(holdPosition.rotation);

            if(fire)
            {
                fire = false;
                heldObject.GetComponent<Rigidbody>().AddForce(transform.forward * 10.0f, ForceMode.Impulse);
                heldObject.GetComponent<Rigidbody>().useGravity = true;
                heldObject = null;
            }
        }
    }
}
