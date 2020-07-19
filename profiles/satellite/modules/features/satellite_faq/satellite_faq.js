(function ($) {
    Drupal.behaviors.satellite_faq = {
        attach: function (context, settings) {
            // FAQ
            $('.faq-list-item-collapsible .faq-answer').once(function () { $(this).hide(); });
            $('.faq-list-item-collapsible .faq-question[data-faq]').click(function () {
                var id = $(this).attr('data-faq');
                if (id) {
                    $('#' + id).toggle('faq-answer-expanded');
                }
            });
        }
    };
}(jQuery));