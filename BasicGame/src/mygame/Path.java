package mygame;


import com.jme3.asset.AssetManager;
import com.jme3.material.Material;
import com.jme3.math.ColorRGBA;
import com.jme3.math.Vector3f;
import com.jme3.scene.Geometry;
import com.jme3.scene.Node;
import com.jme3.scene.Spatial;
import com.jme3.scene.shape.Box;
import java.util.Date;
import java.util.Random;

public class Path {
    private final Node node;
    private final AssetManager assetManager;
    
    public Path(AssetManager assetManager,Vector3f position, boolean good, int level){// 0, 4.5, 10
        this.assetManager = assetManager;
        
        node = new Node();
        Box b = new Box(4.1f, 0.1f, 20); // create a box shape
        Geometry geom1 = new Geometry("Path", b);  // create a cube geometry from the box shape
        Material mat = new Material(assetManager,"Common/MatDefs/Misc/Unshaded.j3md");  // create a simple material
        mat.setColor("Color", ColorRGBA.Pink);   // set color of material to blue
        geom1.setMaterial(mat);       
        geom1.setLocalTranslation(position);// set the cube geometry 's material
        
        Box pathLeft = new Box(0.2f, 0.1f, 20);
        Geometry geom2 = new Geometry("PathRight", pathLeft);
        Material mat2 = new Material(assetManager,"Common/MatDefs/Misc/Unshaded.j3md");
        mat2.setColor("Color", ColorRGBA.White);
        geom2.setMaterial(mat2);       
        geom2.setLocalTranslation(position.setX(4.3f));
        
        Box pathRight = new Box(0.2f, 0.1f, 20);
        Geometry geom3 = new Geometry("PathLeft", pathRight);
        Material mat3 = new Material(assetManager,"Common/MatDefs/Misc/Unshaded.j3md");
        mat3.setColor("Color", ColorRGBA.White);
        geom3.setMaterial(mat3);       
        geom3.setLocalTranslation(position.setX(-4.3f));
        
        Box wallRight = new Box(2.25f, 2f, 0.1f);
        Geometry geom4 = new Geometry("WallLeft", wallRight);
        Material mat4 = new Material(assetManager,"Common/MatDefs/Misc/Unshaded.j3md"); 
        //mat4.setColor("Color", ColorRGBA.Blue);
        geom4.setMaterial(mat4);       
        geom4.setLocalTranslation(position.add(0,0,20).setX(-2.25f).setY(2f));
        
        Box wallLeft = new Box(2.25f, 2f, 0.1f);
        Geometry geom5 = new Geometry("WallRight", wallLeft);
        Material mat5 = new Material(assetManager,"Common/MatDefs/Misc/Unshaded.j3md");
        //mat5.setColor("Color", ColorRGBA.Red);
        geom5.setMaterial(mat5);       
        geom5.setLocalTranslation(position.add(0,0,20f).setX(2.25f).setY(2f));
        ///////////////////////////////////////////////////////////////////////////////////////
        Box brainLeft = new Box(0.5f, 0.5f, 0.11f);
        Geometry geom6 = new Geometry("brainLeft", brainLeft);
        Material mat6 = new Material(assetManager,"Common/MatDefs/Misc/Unshaded.j3md");
        mat6.setTexture("ColorMap", assetManager.loadTexture("Textures/Wall/brain.png"));
        geom6.setMaterial(mat6);       
        geom6.setLocalTranslation(position.add(0,0,20f).setX(3.75f).setY(1.8f));
        
        Box brainRight = new Box(0.5f, 0.5f, 0.11f);
        Geometry geom7 = new Geometry("brainRight", brainRight);
        Material mat7 = new Material(assetManager,"Common/MatDefs/Misc/Unshaded.j3md");
        mat7.setTexture("ColorMap", assetManager.loadTexture("Textures/Wall/brain.png"));
        geom7.setMaterial(mat7);       
        geom7.setLocalTranslation(position.add(0,0,20f).setX(-0.85f).setY(1.8f));
        
        Box opLeft = new Box(0.5f, 0.5f, 0.11f);
        Geometry geom8 = new Geometry("OpLeft", opLeft);
        Material mat8 = new Material(assetManager,"Common/MatDefs/Misc/Unshaded.j3md");
        geom8.setMaterial(mat8);       
        geom8.setLocalTranslation(position.add(0,0,20f).setX(2.7f).setY(1.8f));
        
        Box opRight = new Box(0.5f, 0.5f, 0.11f);
        Geometry geom9 = new Geometry("OpRight", opRight);
        Material mat9 = new Material(assetManager,"Common/MatDefs/Misc/Unshaded.j3md");
        geom9.setMaterial(mat9);       
        geom9.setLocalTranslation(position.add(0,0,20f).setX(-1.9f).setY(1.8f));
        
        //0.9f, 0.5f, 0.11f
        Box numLeft = new Box(0.3f, 0.5f, 0.11f);
        Geometry geom10 = new Geometry("NumLeft", numLeft);
        Material mat10 = new Material(assetManager,"Common/MatDefs/Misc/Unshaded.j3md");
        geom10.setMaterial(mat10);       
        geom10.setLocalTranslation(position.add(0,0,20f).setX(1.25f).setY(1.8f));
        
        
        Box numRight = new Box(0.3f, 0.5f, 0.11f);
        Geometry geom11 = new Geometry("NumRight", numRight);
        Material mat11 = new Material(assetManager,"Common/MatDefs/Misc/Unshaded.j3md");
        geom11.setMaterial(mat11);       
        geom11.setLocalTranslation(position.add(0,0,20f).setX(-3.35f).setY(1.8f));

        ///////////////////////////////////////////////////////////////////////////////////////
        
        Box poleMiddle = new Box(0.1f, 2f, 0.2f);
        Geometry geom12 = new Geometry("poleMiddle", poleMiddle);
        Material mat12 = new Material(assetManager,"Common/MatDefs/Misc/Unshaded.j3md");
        mat12.setColor("Color", ColorRGBA.Black);
        geom12.setMaterial(mat12);       
        geom12.setLocalTranslation(position.add(0,0,20f).setX(0).setY(2f));

        node.setName("Path");
        
        
        randomWall(good,geom8,geom9,geom10,geom11);
        
        
        node.attachChild(geom1);
        node.attachChild(geom2);
        node.attachChild(geom3);
        node.attachChild(geom4);
        node.attachChild(geom5);
        node.attachChild(geom6);
        node.attachChild(geom7);
        node.attachChild(geom8);
        node.attachChild(geom9);
        node.attachChild(geom10);
        node.attachChild(geom11);
        node.attachChild(geom12);
    }
    
    private void randomWall(boolean good,Geometry opLeft, Geometry opRight, Geometry numLeft, Geometry numRight){
        Date date = new Date();
        Random random = new Random(date.getTime());
        int rd1,rd2;
        
        if (good){
            rd1 = random.nextInt(2);
            rd2 = random.nextInt(2);
        }else{
            rd1 = 2 + random.nextInt(2);
            rd2 = 2 + random.nextInt(2);
        }
        
        
        
        int rd3,rd4;
        
        if (rd1 == 1){
            rd3 = random.nextInt(4);
        }else{
            rd3 = random.nextInt(10);
        }
        
        do{
            if (rd2 == 1){
                rd4 = random.nextInt(4);
            }else{
                rd4 = random.nextInt(10);
            }
        }while (rd4 == rd3);
        
        
        
        opLeft.getMaterial().setTexture("ColorMap", assetManager.loadTexture("Textures/Wall/Op/"+rd1+".png"));
        opRight.getMaterial().setTexture("ColorMap", assetManager.loadTexture("Textures/Wall/Op/"+rd2+".png"));
        numLeft.getMaterial().setTexture("ColorMap", assetManager.loadTexture("Textures/Wall/Number/"+rd3+".png"));
        numRight.getMaterial().setTexture("ColorMap", assetManager.loadTexture("Textures/Wall/Number/"+rd4+".png"));
        
        Node n1 = new Node();
        n1.setName(""+rd1);
        Node n2 = new Node();
        n2.setName(""+rd2);
        Node n3 = new Node();
        n3.setName(""+rd3);
        Node n4 = new Node();
        n4.setName(""+rd4);
        
        node.attachChild(n1);
        node.attachChild(n2);
        node.attachChild(n3);
        node.attachChild(n4);
        
    }
    
    public Node getNode(){
        return node;
    }
}
