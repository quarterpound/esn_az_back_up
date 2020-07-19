/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - http://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth

Drupal.behaviors.BASE = {
  attach: function(context, settings) {
	(function ($) {



// ----------------------------------------------------------------
//  MOBILE SWITCH
// ----------------------------------------------------------------

	$('#mobile-search a').click(function(event) {
		event.preventDefault();
		$('#shelf-menu').slideUp(100,"swing");
		$('#shelf-search').slideToggle(300,"swing");
		return false;
	});




// ----------------------------------------------------------------
//  MOBILE MENU
// ----------------------------------------------------------------
	
	function MobileMenu(menu) {


		$(menu).find('li.expanded').each(function(index) {
			$(this).find('ul').hide();
			var path = $(this).find('> a').attr('href');
			var title = $(this).find('> a').text();
			var child = $(this).find('> ul > li').first();
			child.removeClass('first');
			$(child).before('<li class="first leaf"><a href="' + path + '">' + title + '</a>');
		});

		//$(menu).find('li.expanded').prepend($('<span class="expand over closed" href="#">Expand &darr;</span>'));
		//$(menu + ' ul.menu span.over').click(function (event) {

		$(menu).find('li.expanded > a').click(function (event) {
			event.preventDefault();
			if ($(this).siblings('ul').is( ":visible" )){
				$(this).siblings('ul').slideUp('fast');
				$(this).removeClass('opened').addClass('closed');
			} else {
				$(this).siblings('ul').slideDown('fast');
				$(this).removeClass('closed').addClass('opened');
			}
			return false; 
		});
	}

	MobileMenu('#shelf-menu');
	MobileMenu('#st-menu');


// ----------------------------------------------------------------
//  BACK TO TOP
// ----------------------------------------------------------------

	// Hide first
	$("#back-top").hide();

	$(function () {
		// fade in #back-top
		$(window).scroll(function () {
			if ($(this).scrollTop() > 100) {
				$('#back-top').fadeIn();
			} else {
				$('#back-top').fadeOut();
			}
		});
		// scroll body to 0px on click
		$('#back-top a').click(function () {
			$('body,html').animate({
				scrollTop: 0
			}, 1000);
			return false;
		});
	});

	function checkOffset() {
	    if($('#back-top').offset().top + $('#back-top').height() 
	                                           >= $('#footer').offset().top - 10)
	        $('#back-top').css('position', 'absolute');
	    if($(document).scrollTop() + window.innerHeight < $('#footer').offset().top)
	        $('#back-top').css('position', 'fixed'); // restore when you scroll up
	    
	}
	$(document).scroll(function() {
	    checkOffset();
	});

// ----------------------------------------------------------------
//  Footer to the bottom
// ----------------------------------------------------------------
  
  var footerHeight = $('#footer').height();
  $('#main').css('margin-bottom', footerHeight * -1);
  $('#main>.inner').css('margin-bottom', footerHeight);
  
  var mainOffset = $('#header').height();
  $('#main').css('margin-top', mainOffset * -1);
  $('#main>.inner').css('margin-top', mainOffset);
  
  $(window).load(function(){
    // The height from the top needs to be recalculated because of the eventual spotlight etc
    var mainOffset = 0;
    $('#header').nextUntil('#main').andSelf().each( function(){ mainOffset += $(this).height(); });  	
    if ($('#spotlight').length > 0) {
    	mainOffset = 0;
	}
	$('#main').css('margin-top', mainOffset * -1);
    $('#main>.inner').css('margin-top', mainOffset);
  });

// ----------------------------------------------------------------
//  SIDEBAR EFFECT
// ----------------------------------------------------------------

var SidebarMenuEffects = (function() {

 	function hasParentClass( e, classname ) {
		if(e === document) return false;
		if( classie.has( e, classname ) ) {
			return true;
		}
		return e.parentNode && hasParentClass( e.parentNode, classname );
	}

	// http://coveroverflow.com/a/11381730/989439
	function mobilecheck() {
		var check = false;
		(function(a){if(/(android|ipad|playbook|silk|bb\d+|meego).+mobile|avantgo|bada\/|blackberry|blazer|compal|elaine|fennec|hiptop|iemobile|ip(hone|od)|iris|kindle|lge |maemo|midp|mmp|netfront|opera m(ob|in)i|palm( os)?|phone|p(ixi|re)\/|plucker|pocket|psp|series(4|6)0|symbian|treo|up\.(browser|link)|vodafone|wap|windows (ce|phone)|xda|xiino/i.test(a)||/1207|6310|6590|3gso|4thp|50[1-6]i|770s|802s|a wa|abac|ac(er|oo|s\-)|ai(ko|rn)|al(av|ca|co)|amoi|an(ex|ny|yw)|aptu|ar(ch|go)|as(te|us)|attw|au(di|\-m|r |s )|avan|be(ck|ll|nq)|bi(lb|rd)|bl(ac|az)|br(e|v)w|bumb|bw\-(n|u)|c55\/|capi|ccwa|cdm\-|cell|chtm|cldc|cmd\-|co(mp|nd)|craw|da(it|ll|ng)|dbte|dc\-s|devi|dica|dmob|do(c|p)o|ds(12|\-d)|el(49|ai)|em(l2|ul)|er(ic|k0)|esl8|ez([4-7]0|os|wa|ze)|fetc|fly(\-|_)|g1 u|g560|gene|gf\-5|g\-mo|go(\.w|od)|gr(ad|un)|haie|hcit|hd\-(m|p|t)|hei\-|hi(pt|ta)|hp( i|ip)|hs\-c|ht(c(\-| |_|a|g|p|s|t)|tp)|hu(aw|tc)|i\-(20|go|ma)|i230|iac( |\-|\/)|ibro|idea|ig01|ikom|im1k|inno|ipaq|iris|ja(t|v)a|jbro|jemu|jigs|kddi|keji|kgt( |\/)|klon|kpt |kwc\-|kyo(c|k)|le(no|xi)|lg( g|\/(k|l|u)|50|54|\-[a-w])|libw|lynx|m1\-w|m3ga|m50\/|ma(te|ui|xo)|mc(01|21|ca)|m\-cr|me(rc|ri)|mi(o8|oa|ts)|mmef|mo(01|02|bi|de|do|t(\-| |o|v)|zz)|mt(50|p1|v )|mwbp|mywa|n10[0-2]|n20[2-3]|n30(0|2)|n50(0|2|5)|n7(0(0|1)|10)|ne((c|m)\-|on|tf|wf|wg|wt)|nok(6|i)|nzph|o2im|op(ti|wv)|oran|owg1|p800|pan(a|d|t)|pdxg|pg(13|\-([1-8]|c))|phil|pire|pl(ay|uc)|pn\-2|po(ck|rt|se)|prox|psio|pt\-g|qa\-a|qc(07|12|21|32|60|\-[2-7]|i\-)|qtek|r380|r600|raks|rim9|ro(ve|zo)|s55\/|sa(ge|ma|mm|ms|ny|va)|sc(01|h\-|oo|p\-)|sdk\/|se(c(\-|0|1)|47|mc|nd|ri)|sgh\-|shar|sie(\-|m)|sk\-0|sl(45|id)|sm(al|ar|b3|it|t5)|so(ft|ny)|sp(01|h\-|v\-|v )|sy(01|mb)|t2(18|50)|t6(00|10|18)|ta(gt|lk)|tcl\-|tdg\-|tel(i|m)|tim\-|t\-mo|to(pl|sh)|ts(70|m\-|m3|m5)|tx\-9|up(\.b|g1|si)|utst|v400|v750|veri|vi(rg|te)|vk(40|5[0-3]|\-v)|vm40|voda|vulc|vx(52|53|60|61|70|80|81|83|85|98)|w3c(\-| )|webc|whit|wi(g |nc|nw)|wmlb|wonu|x700|yas\-|your|zeto|zte\-/i.test(a.substr(0,4)))check = true})(navigator.userAgent||navigator.vendor||window.opera);
		return check;
	}

	function init() {

		var container = document.getElementById( 'st-container' ),
			buttons = Array.prototype.slice.call( document.querySelectorAll( '#mobile-menu a' ) ),
			// event type (if mobile use touch events)
			eventtype = mobilecheck() ? 'touchstart' : 'click',
			resetMenu = function() {
				classie.remove( container, 'st-menu-open' );
			},
			bodyClickFn = function(evt) {
				if( !hasParentClass( evt.target, 'st-menu' ) ) {
					resetMenu();
					document.removeEventListener( eventtype, bodyClickFn );
				}
			};

		buttons.forEach( function( el, i ) {
			var effect = 'st-effect-3';

			el.addEventListener( eventtype, function( ev ) {
				ev.stopPropagation();
				ev.preventDefault();
				container.className = 'st-container'; // clear
				classie.add( container, effect );
				setTimeout( function() {
					classie.add( container, 'st-menu-open' );
				}, 25 );
				document.addEventListener( eventtype, bodyClickFn );
			});
		} );

	}

	init();

})();




// END OF BEHAVIOUR	
	})(jQuery);
	}
};
