using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class LogicMainMenu : LogicMenu
{
    [SerializeField] Button startButton = null;
    [SerializeField] Button quitButton = null;

	protected override void Awake()
	{
        base.Awake ();
        startButton.onClick.AddListener(StartGame);
        quitButton.onClick.AddListener(QuitGame);
	}

	void Start()
    {
        switchPanel = hud.AllSwitchPanel[typeMenu];
	}

    void StartGame()
    {
        StartCoroutine(LoadNewScene()); 
	}

    IEnumerator LoadNewScene()
	{
        AsyncOperation _operation = SceneManager.LoadSceneAsync(1);
        yield return _operation;
    }

	void QuitGame()
    {
    }
}
