package mygame;

import com.jme3.animation.AnimChannel;
import com.jme3.animation.AnimControl;
import com.jme3.app.SimpleApplication;
import com.jme3.app.state.ScreenshotAppState;
import com.jme3.asset.TextureKey;
import com.jme3.audio.AudioNode;
import com.jme3.export.binary.BinaryExporter;
import com.jme3.export.binary.BinaryImporter;
import com.jme3.font.BitmapText;
import com.jme3.input.KeyInput;
import com.jme3.input.controls.ActionListener;
import com.jme3.input.controls.KeyTrigger;
import com.jme3.material.Material;
import com.jme3.math.ColorRGBA;
import com.jme3.math.Quaternion;
import com.jme3.math.Vector3f;
import com.jme3.scene.Geometry;
import com.jme3.scene.Node;
import com.jme3.scene.Spatial;
import com.jme3.scene.shape.Box;
import com.jme3.system.AppSettings;
import com.jme3.system.JmeCanvasContext;
import com.jme3.texture.Texture;
import de.lessvoid.nifty.screen.Screen;
import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Toolkit;
import java.io.File;
import java.io.IOException;
import java.util.concurrent.TimeUnit;
import java.util.logging.Level;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JLayeredPane;
import javax.swing.JPanel;




public class Main extends SimpleApplication {
    private Node loadedNode;
    private Player player;
    private boolean walk[];
    private boolean specter;
    private final ActionListener actionListener = new ActionListener() {
            @Override
            public void onAction(String name, boolean keyPressed, float tpf) {
                int number = -1;
                switch (name) {
                    case "P":
                        if (keyPressed){
                            specter = !specter;
                            specterMode();
                        }
                        break;
                    case "Up":
                    case "W":
                        number = 0;
                        break;
                    case "Left":
                    case "A":
                        number = 1;
                        break;
                    case "Down":
                    case "S":
                        number = 2;
                        break;
                    case "Right":
                    case "D":
                        number = 3;
                        break;
                    default:
                        break;
                }
                if (number != -1) walk[number] = keyPressed;
            }
        };
    private Vector3f positionSpawnPath;
    private AudioNode music;
    private BitmapText scoreText;
    private BitmapText brainText;
    private int good;
    private AnimControl playerAnimation;
    private AnimChannel animationChannel;
    
    public static void main(String[] args) {
        Main app = new Main();
        ////////////////////////////////////////////////////////////////////////
//        app.createCanvas();
//        JmeCanvasContext ctx = (JmeCanvasContext) app.getContext();
//        ctx.setSystemListener(app);
//        Dimension dim = new Dimension(1920, 1080);
//        ctx.getCanvas().setPreferredSize(dim);
//        ctx.getCanvas().setBackground(Color.pink);
//        
//        JFrame frame = new JFrame("Our's Game");
//        
//        JPanel panel = new JPanel(); // a panel
//        JLabel jlab = new JLabel("Hello");
//
////        // add all your Swing components ...
//        JButton bt1 = new JButton("press me!!!");
//        
//        // add the JME canvas
//        panel.add(ctx.getCanvas());
//        bt1.setLocation(0, 0);
//        
//        //panel.add(bt1);
//        frame.add(jlab);
//        frame.add(panel);
//        
//        frame.setLayout(new FlowLayout());
//        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//        frame.setUndecorated(true);
//        frame.pack();
//        frame.setLocationRelativeTo(null);
//        frame.setVisible(true);
//        frame.setName("My game");
//        frame.setLocationByPlatform(true);
        ////////////////////////////////////////////////////////////////////////
        app.showSettings = false; 
        AppSettings appSettings = new AppSettings(true);
        appSettings.put("Width",1920);
        appSettings.put("Height",1080);  
        appSettings.put("Title", "Our's game");
        appSettings.put("Fullscreen", false);
        appSettings.setVSync(true);
           
        app.setSettings(appSettings);  
        app.start();
    }
    @Override
    public void simpleUpdate(float tpf) {
        updateCharacterPosition();
        updatePath();
        updateText();
    }
    @Override
    public void simpleInitApp() {
        ScreenshotAppState screenShotState = new ScreenshotAppState();
        this.stateManager.attach(screenShotState);
        //////////////////////////////////////////////////////////////
        File scene = new File("assets\\Scenes\\Game.j3o");
        BinaryImporter importer = BinaryImporter.getInstance();
        importer.setAssetManager(assetManager); 
        try {
            loadedNode = (Node ) importer.load(scene);
            loadedNode.setName ("Game");
            rootNode.attachChild(loadedNode);
        } catch (IOException ex) {
            System.out.println("Error to load Node");
        }
        //////////////////////////////////////////////////////////////
        initVariable();
        initCharacter();
        initPath();
        initMusic();
        initKeyboard();
        initCamera();
        initEnvi();
        initGUI();
        /////////////////////////////////////////////////////////////
        specterMode();
        test();
    }
    
    private void initMusic(){
        music = new AudioNode(assetManager, "Sounds/song/never-gonna-give-you-up-official-music-video.wav",true);
        music.setName("Music");
        music.setPositional(false);
        music.setLooping(false);
        music.setVolume(1);
        rootNode.attachChild(music);
        //music.play();
    }
    private void initPath(){
        rootNode.attachChild(new Path(assetManager,new Vector3f(0, -0.05f, 17.5f),true,player.getLevel()).getNode());
        rootNode.attachChild(new Path(assetManager,new Vector3f(0, -0.05f, 47.5f),true,player.getLevel()).getNode());
        rootNode.attachChild(new Path(assetManager,new Vector3f(0, -0.05f, 77.5f),true,player.getLevel()).getNode());
        rootNode.attachChild(new Path(assetManager,new Vector3f(0, -0.05f, 107.5f),false,player.getLevel()).getNode());
         /** Save a Node to a .j3o file. */
        String userHome = System.getProperty("user.home");
        BinaryExporter exporter = BinaryExporter.getInstance();
        File file = new File("assets\\Scenes\\save.j3o");
        try {
          exporter.save(rootNode, file);
            System.out.println("Success");
        } catch (IOException ex) {
          //Logger.getLogger(Main.class.getName()).log(Level.SEVERE, "Failed to save node!", ex);
            System.out.println("Eorror !!!");
        } 
    }
    private void initKeyboard(){
        inputManager.addMapping("P", new KeyTrigger(KeyInput.KEY_P));        
        inputManager.addMapping("Up", new KeyTrigger(KeyInput.KEY_UP));   
        inputManager.addMapping("Down", new KeyTrigger(KeyInput.KEY_DOWN));   
        inputManager.addMapping("Left", new KeyTrigger(KeyInput.KEY_LEFT));   
        inputManager.addMapping("Right", new KeyTrigger(KeyInput.KEY_RIGHT));   
        inputManager.addMapping("W", new KeyTrigger(KeyInput.KEY_W));   
        inputManager.addMapping("A", new KeyTrigger(KeyInput.KEY_A));   
        inputManager.addMapping("S", new KeyTrigger(KeyInput.KEY_S));   
        inputManager.addMapping("D", new KeyTrigger(KeyInput.KEY_D));   
        inputManager.addListener(actionListener, "P");
        inputManager.addListener(actionListener, "Up");
        inputManager.addListener(actionListener, "Down");
        inputManager.addListener(actionListener, "Left");
        inputManager.addListener(actionListener, "Right");
        inputManager.addListener(actionListener, "W");
        inputManager.addListener(actionListener, "A");
        inputManager.addListener(actionListener, "S");
        inputManager.addListener(actionListener, "D");
    }
    private void initCharacter(){
        player = new Player((Node)loadedNode.getChildren().get(0));
        player.setLocalTranslation(0,0.05f,0);
//        playerAnimation = player.getNode().getControl(AnimControl.class);
//        playerAnimation.addListener(this);
//        animationChannel = playerAnimation.createChannel();
//        animationChannel.setAnim("stand");
    }
    private void initCamera(){
        //0,5,-8
        Vector3f CamPosition = new Vector3f(0,5,-8);
        Quaternion CamRotation = new Quaternion((float)0.185,0,0,5);
        this.cam.setLocation(CamPosition);
        this.cam.setRotation(CamRotation);
        this.flyCam.setMoveSpeed(10);
    }
    private void initVariable(){
        walk = new boolean[5];
        specter = false;
        positionSpawnPath = new Vector3f(0, -0.05f, 17.5f);
        good = 1;
    }
    private void initEnvi(){
        viewPort.setBackgroundColor(ColorRGBA.Gray);
    }
    private void initGUI(){
        guiNode.detachAllChildren();
        guiFont = assetManager.loadFont("Interface/Fonts/Default.fnt");
        
        BitmapText textScore = new BitmapText(guiFont, false);
        textScore.setSize(20);
        textScore.setText("Our team is so Beautiful");
        textScore.setLocalTranslation(1700, 1050, 0);
        textScore.setColor(ColorRGBA.Black);
        guiNode.attachChild(textScore);
        
        scoreText = new BitmapText(guiFont, false);
        scoreText.setSize(20);
        scoreText.setText("0");
        scoreText.setLocalTranslation(1800, 1025, 0);
        scoreText.setColor(ColorRGBA.Black);
        guiNode.attachChild(scoreText);
        
        brainText = new BitmapText(guiFont, false);
        brainText.setSize(30);
        brainText.setText("1");
        brainText.setLocalTranslation(960, 50, 0);
        brainText.setColor(ColorRGBA.Black);
        guiNode.attachChild(brainText);
    }
    
    private void updatePath(){
        if (specter) return;
        for (Spatial s:rootNode.getChildren()){
            if (s.getName()!=null && s.getName().equals("Path")){
                float wallPositionZ = ((Node)s).getChild("WallLeft").getWorldTranslation().z;
                Vector3f playerPosition = loadedNode.getChild(0).getWorldTranslation();
                if (wallPositionZ < playerPosition.z){
                    boolean g = (good==1);
                    good = (good==1?0:1);
                    hitWall(playerPosition.x, s);
                    rootNode.detachChild(s);
                    rootNode.attachChild(new Path(assetManager,new Vector3f(0, -0.05f, (wallPositionZ)+100),g,player.getLevel()).getNode());
                }
                //0,0,-0.05
                s.move(0, 0, -0.15f);
                
            }
        }
        
    }
    private void updateText(){
        float playerPositionZ = player.getLocalTranslation().z;
        brainText.setLocalTranslation(new Vector3f(960-brainText.getLineWidth()/2, 450+playerPositionZ*50, 0));
        changeScore(1);
    }
    private void updateCharacterPosition(){
        Vector3f position = player.getLocalTranslation();
        float x = position.x;
        float y = position.y;
        float z = position.z;
        float defaultSpeed = (float)0.08;
        /*
        if (walk[4]){
            speedCharacter = (float)(1/Math.sqrt(defaultSpeed));
        }*/
        if (specter)return;
        if (walk[0])z+=defaultSpeed;//up
        if (walk[1])x+=defaultSpeed;//left
        if (walk[2])z-=defaultSpeed;//down
        if (walk[3])x-=defaultSpeed;//right
        
        
        if (x<-4f || x>4f){
            x = (float)(4*(x/Math.abs(x)));
        }else{
            if (walk[1])cam.setLocation(cam.getLocation().add(defaultSpeed, 0, 0));
            if (walk[3])cam.setLocation(cam.getLocation().add(-defaultSpeed, 0, 0));
        }
        if (z<-1.5f){
            z = -1.5f;
        }else if (z>5){
            z = 5f;
        }
        player.setLocalTranslation(x, y, z);
    }
    
    private void specterMode(){
        this.flyCam.setEnabled(specter);
        this.setDisplayFps(specter);  
        this.setDisplayStatView(specter);
        
        /*bug
        if (specter){
            music.pause();
        }else{
            music.play();
        }*/
    }
    private void test(){

    }    
    private void changeScore(int change){
        scoreText.setText(""+player.addScore(change));
    }
    private void hitWall(float position, Spatial wall){
        
        int opNum;
        int number;
        
        if (position >= 0){
            opNum = Integer.parseInt(((Node)wall).getChild(0).getName());
            number = Integer.parseInt(((Node)wall).getChild(2).getName());
        }else{
            opNum = Integer.parseInt(((Node)((Node)wall).getChild(1)).getName());
            number = Integer.parseInt(((Node)((Node)wall).getChild(3)).getName());
        }
        
        switch (opNum){
            case 0: 
                player.setBrain(player.getBrain() + number);
                break;
            case 1: 
                player.setBrain(player.getBrain() * number);
                break;
            case 2: 
                player.setBrain(player.getBrain() - number);
                break;
            case 3: 
                if (number != 0){
                    player.setBrain((int)(player.getBrain() / number));
                    break;
                }else{
                    player.setBrain(0);
                }
                break;
            default:
                break;
        }
        brainText.setText(""+player.getBrain());
                
    }
        
}
