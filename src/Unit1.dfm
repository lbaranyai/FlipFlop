object Form1: TForm1
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Flip-Flop'
  ClientHeight = 480
  ClientWidth = 641
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 0
    Width = 641
    Height = 461
    Align = alClient
    OnMouseUp = Image1MouseUp
    ExplicitLeft = 96
    ExplicitTop = 80
    ExplicitWidth = 105
    ExplicitHeight = 105
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 461
    Width = 641
    Height = 19
    Panels = <
      item
        Alignment = taCenter
        Text = '00 : 00'
        Width = 100
      end
      item
        Alignment = taRightJustify
        Text = '0 steps'
        Width = 100
      end
      item
        Alignment = taCenter
        Text = 'Click on board to flip-flop tile and neighbors.'
        Width = 50
      end>
    ExplicitLeft = 440
    ExplicitTop = 448
    ExplicitWidth = 0
  end
  object MainMenu1: TMainMenu
    Left = 216
    Top = 240
    object File1: TMenuItem
      Caption = 'File'
      object Resetgame1: TMenuItem
        Caption = 'Reset game'
        Hint = 'Restart game with clean board'
        ShortCut = 16466
        OnClick = Resetgame1Click
      end
      object N1: TMenuItem
        Caption = '-'
      end
      object Tiles2x2: TMenuItem
        Caption = 'Tiles 2 x 2'
        GroupIndex = 2
        RadioItem = True
        OnClick = Tiles2x2Click
      end
      object Tiles3x3: TMenuItem
        Caption = 'Tiles 3 x 3'
        GroupIndex = 2
        RadioItem = True
        OnClick = Tiles3x3Click
      end
      object Tiles4x4: TMenuItem
        Caption = 'Tiles 4 x 4'
        Checked = True
        GroupIndex = 2
        RadioItem = True
        OnClick = Tiles4x4Click
      end
      object Tiles5x5: TMenuItem
        Caption = 'Tiles 5 x 5'
        GroupIndex = 2
        RadioItem = True
        OnClick = Tiles5x5Click
      end
      object N2: TMenuItem
        Caption = '-'
        GroupIndex = 101
      end
      object Exit1: TMenuItem
        Caption = 'Exit'
        GroupIndex = 102
        Hint = 'Quit from game'
        ShortCut = 16465
        OnClick = Exit1Click
      end
    end
    object HuEn1: TMenuItem
      Caption = 'Hu/En'
      object Hungarian1: TMenuItem
        Caption = 'Magyar'
        GroupIndex = 200
        RadioItem = True
        OnClick = Hungarian1Click
      end
      object English1: TMenuItem
        Caption = 'English'
        Checked = True
        GroupIndex = 200
        RadioItem = True
        OnClick = English1Click
      end
    end
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 288
    Top = 240
  end
end
