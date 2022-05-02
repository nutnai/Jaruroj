package mygame;

import com.jme3.math.Vector3f;
import com.jme3.scene.Node;

public class Player{
    private final Node model;
    private int score;
    private int level;
    private int brain;
    
    public Player(Node model){
        this.model = model;
        brain = 1;
    }
    
    public int addScore(int change){
        this.score += change;
        return this.score;
    }
    public int addBrain(int change){
        this.brain += change;
        return brain;
    }
    
    public void setLevel(int level){
        this.level = level;
    }
    public void setScore(int score) {
        this.score = score;
    }
    public void setBrain(int brain){
        this.brain = brain;
    }
    public void setLocalTranslation(float x, float y, float z){
        model.setLocalTranslation(x,y,z);
    }
    
    public Node getNode(){
        return this.model;
    }
    public int getScore() {
        return score;
    }
    public int getLevel() {
        return level;
    }
    public int getBrain(){
        return brain;
    }
    
    public Vector3f getLocalTranslation(){
        return this.model.getLocalTranslation();
    }
}