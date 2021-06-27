using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public interface IState
{
    void Enter();
    void Execute();
    void Exit();
}
public class StateMachine 
{
    IState currentState;
    private EnemyController enemyController;

    public StateMachine(EnemyController enemyController)
    {
        this.enemyController = enemyController;
    }

    public StateMachine()
    {
    }

    public void ChangeState(IState newState)
    {
        if (currentState != null)
            currentState.Exit();
        currentState = newState;
        currentState.Enter();
    }

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    public void Update()
    {
        if (currentState != null) currentState.Execute();

    }
}
