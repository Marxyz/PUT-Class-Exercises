using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;
using Windows.UI.Xaml.Shapes;

// The User Control item template is documented at https://go.microsoft.com/fwlink/?LinkId=234236

namespace CreativeMirrocle
{
    public sealed partial class Clock : UserControl
    {
        public Clock()
        {
            this.InitializeComponent();
            init();

        }

        private DispatcherTimer timer = new DispatcherTimer();

        private Canvas markers = new Canvas();
        private Canvas face = new Canvas();

        private Rectangle secondHand;
        private Rectangle minuteHand;
        private Rectangle hourHand;

        private Brush rimForegroundColor = new SolidColorBrush(Colors.Black);
        private Brush rimBackgroundColor = new SolidColorBrush(Colors.White);

        private int secondsWidth = 1;
        private int secondsHeight;
        private int minutesWidth = 5;
        private int minutesHeight;
        private int hoursWidth = 8;
        private int hoursHeight;
        private double diameter;
        private bool isrealtime = true;
        private bool showSeconds = true;
        private bool showHours = true;
        private bool showMinutes = true;

        public bool IsRealTime { get { return isrealtime; } set { isrealtime = value; } }
        public bool ShowSeconds { get { return showSeconds; } set { showSeconds = value; } }
        public bool ShowMinutes { get { return showMinutes; } set { showMinutes = value; } }
        public bool ShowHours { get { return showHours; } set { showHours = value; } }
        public DateTime Time { get; set; }
        public int fontSize { get; set; }


        private Rectangle Hand(double width, double height, double radiusX, double radiusY, double thickness)
        {
            Rectangle hand = new Rectangle();
            hand.Width = width;
            hand.Height = height;
            hand.Fill = Foreground;
            hand.RadiusX = radiusX;
            hand.RadiusY = radiusY;
            hand.StrokeThickness = thickness;
            return hand;
        }

        private void RemoveHand(ref Rectangle hand)
        {
            if (hand != null && face.Children.Contains(hand))
            {
                face.Children.Remove(hand);
            }
        }

        private void addHand(ref Rectangle hand)
        {
            if (!face.Children.Contains(hand))
            {
                face.Children.Add(hand);
            }
        }
        private TransformGroup transformGroup(double angle, double x, double y)
        {
            TransformGroup transformGroup = new TransformGroup();
            TranslateTransform firstTranslate = new TranslateTransform();
            firstTranslate.X = x;
            firstTranslate.Y = y;
            transformGroup.Children.Add(firstTranslate);
            RotateTransform rotateTransform = new RotateTransform();
            rotateTransform.Angle = angle;
            transformGroup.Children.Add(rotateTransform);
            TranslateTransform secondTranslate = new TranslateTransform();
            secondTranslate.X = diameter / 2;
            secondTranslate.Y = diameter / 2;
            transformGroup.Children.Add(secondTranslate);
            return transformGroup;
        }
        private void MakesecondsHand(int seconds)
        {
            RemoveHand(ref secondHand);
            if (ShowSeconds)
            {
                secondHand = Hand(secondsWidth, secondsHeight, 0, 0, 0);
                secondHand.RenderTransform = transformGroup(seconds * 6,
                -secondsWidth / 2, -secondsHeight + 4.25);
                addHand(ref secondHand);
            }
        }
        private void MakeminutesHand(int minutes, int seconds)
        {
            RemoveHand(ref minuteHand);
            if (ShowMinutes)
            {
                minuteHand = Hand(minutesWidth, minutesHeight, 2, 2, 0.6);
                minuteHand.RenderTransform = transformGroup(6 * minutes + seconds / 10,
                -minutesWidth / 2, -minutesHeight + 4.25);
                addHand(ref minuteHand);
            }
        }
        private void MakeHourHand(int hours, int minutes, int seconds)
        {
            RemoveHand(ref hourHand);
            if (ShowHours)
            {
                hourHand = Hand(hoursWidth, hoursHeight, 3, 3, 0.6);
                hourHand.RenderTransform = transformGroup(30 * hours + minutes / 2 + seconds / 120,
                -hoursWidth / 2, -hoursHeight + 4.25);
                addHand(ref hourHand);
            }
        }

        private void Layout(ref Canvas canvas)
        {
            Ellipse rim = new Ellipse();
            canvas.Children.Clear();
            diameter = canvas.Width;
            double inner = diameter - 15;
            rim.Height = diameter;
            rim.Width = diameter;
            rim.Stroke = RimBackground;
            rim.StrokeThickness = 20;
            canvas.Children.Add(rim);
            markers.Children.Clear();
            markers.Width = inner;
            markers.Height = inner;
            for (int i = 0; i < 60; i++)
            {

                Windows.UI.Xaml.Shapes.Rectangle marker = new Windows.UI.Xaml.Shapes.Rectangle();
                marker.Fill = RimForeground;
                if ((i % 5) == 0)
                {
                    marker.Width = 3;
                    marker.Height = 8;
                    marker.RenderTransform = transformGroup(i * 6, -(marker.Width / 2),
                    -(marker.Height * 2 + 4.5 - rim.StrokeThickness / 2 - inner / 2 - 6));
                }
                else
                {
                    marker.Width = 1;
                    marker.Height = 4;
                    marker.RenderTransform = transformGroup(i * 6, -(marker.Width / 2),
                    -(marker.Height * 2 + 12.75 - rim.StrokeThickness / 2 - inner / 2 - 8));
                }
                markers.Children.Add(marker);
            }
            canvas.Children.Add(markers);
            face.Width = diameter;
            face.Height = diameter;
            canvas.Children.Add(face);
            secondsHeight = (int)diameter / 2 - 20;
            minutesHeight = (int)diameter / 2 - 40;
            hoursHeight = (int)diameter / 2 - 60;
        }

        private void init()
        {
            Layout(ref Display);
            timer.Interval = TimeSpan.FromSeconds(1);
            ClockTextBlock.FontSize = fontSize;
            timer.Tick += (object sender, object e) =>
            {
                ClockTextBlock.Text = string.Format("{0}:{1}", Time.Hour, Time.Minute);
                if (IsRealTime) Time = DateTime.Now;
                MakesecondsHand(Time.Second);
                MakeminutesHand(Time.Minute, Time.Second);
                MakeHourHand(Time.Hour, Time.Minute, Time.Second);

            };
            timer.Start();
        }

        public Brush RimForeground
        {
            get { return rimForegroundColor; }
            set
            {
                rimForegroundColor = value == null ? new SolidColorBrush(Windows.UI.Colors.Black) : value;
                Layout(ref Display);
            }
        }

        public Brush RimBackground
        {
            get { return rimBackgroundColor; }
            set
            {
                rimBackgroundColor = value == null ? new SolidColorBrush(Windows.UI.Colors.White) : value;
                Layout(ref Display);
            }
        }

        

        public bool Enabled
        {
            get { return timer.IsEnabled; }
            set
            {
                if (timer.IsEnabled)
                {
                    timer.Stop();
                }
                else
                {
                    timer.Start();
                }
            }
        }
    }
}
