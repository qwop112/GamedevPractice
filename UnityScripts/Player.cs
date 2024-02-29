using System.Collections;
using System.Collections.Generic;
using System.Net.Sockets;
using UnityEngine;
using UnityEngine.InputSystem;

public class Player : MonoBehaviour
{
    public Vector2 inputVec;
    public float moveSpeed;
    public Scanner scanner;
    public Hand[] hands;

    Rigidbody2D rigid;
    SpriteRenderer spriteRenderer;
    Animator anim;

    // Start is called before the first frame update
    void Awake()
    {
        rigid = GetComponent<Rigidbody2D>();
        spriteRenderer = GetComponent<SpriteRenderer>();
        anim = GetComponent<Animator>();
        scanner = GetComponent<Scanner>();
        hands = GetComponentsInChildren<Hand>(true);
    }


    void OnMove(InputValue value)
    {
        inputVec = value.Get<Vector2>();
    }

    

    private void FixedUpdate()
    {
        if (!GameManager.instance.isLive)
            return;

        Vector2 nextVec = inputVec * moveSpeed * Time.fixedDeltaTime;
        rigid.MovePosition(rigid.position + nextVec );
    }
    private void LateUpdate()
    {
        if (!GameManager.instance.isLive)
            return;

        anim.SetFloat("Speed", inputVec.magnitude);

        if (inputVec.x != 0)
        {
            spriteRenderer.flipX = (inputVec.x < 0);
        }
    }

    private void OnCollisionStay2D(Collision2D collision)
    {
        if (!GameManager.instance.isLive)
            return;

        GameManager.instance.health -= Time.deltaTime * 10;

        if (GameManager.instance.health < 0)
        {
            for (int index=2; index <transform.childCount; index++)
            {
                transform.GetChild(index).gameObject.SetActive(false);
            }


            anim.SetTrigger("Dead");
            GameManager.instance.GameOver();

        }

    }

}
