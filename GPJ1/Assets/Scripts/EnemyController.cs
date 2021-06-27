using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class EnemyController : MonoBehaviour
{
    
    public Waypoint waypoint;
    public GameObject target;
    public StateMachine stateMachine = new StateMachine();
    // Start is called before the first frame update

    void Start()
    {
        stateMachine.ChangeState(new State_Patrol(this));
    }
    public Transform shotTransform;

    public GameObject bullet;
    private float nextFire = 0.0f;
    public float fireRate = 0.5f;
    public void fire()
    {
        if (Time.time > nextFire)
        {
            nextFire = Time.time + fireRate;
            Quaternion rotation = Quaternion.LookRotation(lastSeenPosition - shotTransform.position, Vector3.up);
            Instantiate(bullet, shotTransform.position, rotation);
        }
    }
    // Update is called once per frame
    void Update()
    {
        stateMachine.Update();
    }
    float sightFov = 180.0f;
    public bool seenTarget = false;
    public Vector3 lastSeenPosition;
    private void OnTriggerStay(Collider other)
    {
        // is it the player?
        if (other.gameObject == target)
        {
            // angle between us and the player
            Vector3 direction = other.transform.position - transform.position;
            float angle = Vector3.Angle(direction, transform.forward);
            // reset whether we¡¯ve seen the player

            RaycastHit hit;
            seenTarget = false;
            // is it less than our field of view
            if (angle < sightFov * 0.5f)
            {
                // if the raycast hits the player we know
                // there is nothing in the way
                // adding transform.up raises up from the floor by 1 unit
                if (Physics.Raycast(transform.position + transform.up,
                direction.normalized,
               out hit,
               GetComponent<SphereCollider>().radius))
                {
                    if (hit.collider.gameObject == target)
                    {
                        // flag that we've seen the player
                        // remember their position
                        seenTarget = true;
                        lastSeenPosition = target.transform.position;
                    }
                }
            }
        }
    }
    void OnDrawGizmos()
    {
        Gizmos.color = Color.blue;
        if (GetComponent<SphereCollider>() != null)
        {
            Gizmos.DrawWireSphere(transform.position, GetComponent<SphereCollider>().radius);
            if (seenTarget)
                Gizmos.DrawLine(transform.position, lastSeenPosition);
            if (lastSeenPosition != Vector3.zero)
                Gizmos.DrawWireSphere(lastSeenPosition, 1.0f);
            // draw a small sphere
            // calculate left fov vector
            Vector3 rightPeripheral;
            Vector3 leftPeripheral;
            rightPeripheral = Quaternion.AngleAxis(-sightFov * 0.5f, Vector3.up)
             * transform.forward * GetComponent<SphereCollider>().radius + transform.position;
            leftPeripheral = Quaternion.AngleAxis(sightFov * 0.5f, Vector3.up)
             * transform.forward * GetComponent<SphereCollider>().radius + transform.position;
            Gizmos.DrawLine(transform.position, rightPeripheral);
            Gizmos.DrawLine(transform.position, leftPeripheral);

            // draw lines for the left and right edges of the field of view
        }
    }
}
